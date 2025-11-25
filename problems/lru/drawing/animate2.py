import os
import xml.etree.ElementTree as ET
import uuid
import re

def make_unique_ids(svg_root, prefix):
    """
    Make all ids unique and update references to them inside the SVG.
    """
    id_map = {}

    # First, rename all ids
    for elem in svg_root.iter():
        if 'id' in elem.attrib:
            old_id = elem.attrib['id']
            new_id = f"{prefix}_{old_id}_{uuid.uuid4().hex[:6]}"
            id_map[old_id] = new_id
            elem.attrib['id'] = new_id

    # Then, update references in attributes
    url_ref_regex = re.compile(r'url\(#([^\)]+)\)')

    for elem in svg_root.iter():
        for attr in elem.attrib:
            val = elem.attrib[attr]
            # Update url(#id) references
            def repl(match):
                old = match.group(1)
                return f"url(#{id_map.get(old, old)})"
            val = url_ref_regex.sub(repl, val)
            elem.attrib[attr] = val
            # Also update href references (xlink:href or href)
            if val.startswith('#') and val[1:] in id_map:
                elem.attrib[attr] = f"#{id_map[val[1:]]}"

def combine_svgs(svg_files, output_file, duration_per_svg=2):
    """Combine multiple SVGs into a single animated SVG."""
    if not svg_files:
        return

    base_tree = ET.parse(svg_files[0])
    base_root = base_tree.getroot()
    ET.register_namespace("", "http://www.w3.org/2000/svg")

    base_root.attrib['style'] = 'overflow:visible'
    base_root_children = list(base_root)
    for child in base_root_children:
        base_root.remove(child)

    for idx, file in enumerate(svg_files):
        tree = ET.parse(file)
        root = tree.getroot()
        make_unique_ids(root, f"svg{idx}")

        g = ET.Element('g', attrib={'id': f"group_{idx}"})
        g.extend(list(root))
        base_root.append(g)

        anim = ET.Element('animate', attrib={
            'attributeName': 'display',
            'values': ';'.join(['inline' if i == idx else 'none' for i in range(len(svg_files))]),
            'dur': f"{duration_per_svg * len(svg_files)}s",
            'begin': '0s',
            'repeatCount': 'indefinite'
        })
        g.append(anim)

    ET.ElementTree(base_root).write(output_file, encoding='utf-8', xml_declaration=True)
    print(f"Combined SVG animation saved to {output_file}")

if __name__ == "__main__":
    folder = "svgs"
    files = [os.path.join(folder, f) for f in os.listdir(folder) if f.endswith(".svg")]
    combine_svgs(files, "combined_animation.svg")
