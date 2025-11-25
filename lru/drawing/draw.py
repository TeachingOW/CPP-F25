from pathlib import Path

frames = [
    ("1", ["A", "", ""], 0),
    ("2", ["B", "A", ""], 1),
    ("3", ["C", "B", "A"], 2),
    ("4", ["A", "C", "B"], 2),
    ("5", ["D", "A", "C"], 2),
    ("6", ["B", "D", "A"], 2),
    ("7", ["E", "B", "D"], 2),
]

out_dir = Path(".")
paths = []

for i, (title, slots, lru_index) in enumerate(frames, start=1):
    width = 700
    height = 260
    slot_w = 150
    slot_h = 120
    gap = 40
    start_x = 50
    start_y = 50+20
    svg_elements = []

    svg_elements.append(f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" viewBox="0 0 {width} {height}">')
    svg_elements.append(f'<rect width="100%" height="100%" fill="white"/>')
    # Title
    # svg_elements.append(f'<text x="{width/2}" y="28" font-family="Helvetica, Arial, sans-serif" font-size="20" text-anchor="middle" fill="#111">{title}</text>')

    # Draw slots and letters
    for idx, label in enumerate(slots):
        x = start_x + idx * (slot_w + gap)
        y = start_y
        svg_elements.append(f'<rect x="{x}" y="{y}" width="{slot_w}" height="{slot_h}" rx="12" ry="12" fill="none" stroke="#111" stroke-width="4"/>')
        if label:
            svg_elements.append(f'<text x="{x + slot_w/2}" y="{y + slot_h/2 + 6}" font-family="Helvetica, Arial, sans-serif" font-size="56" font-weight="700" text-anchor="middle" fill="#111">{label}</text>')

    # MRU -> LRU label
    svg_elements.append(f'<text x="{start_x + (slot_w*1.5 + gap)}" y="{start_y + slot_h + 38}" font-family="Helvetica, Arial, sans-serif" font-size="12" text-anchor="middle" fill="#111">Most Recently Used → Least Recently Used (left → right)</text>')
    svg_elements.append(f'<text x="{width/2}" y="{start_y + slot_h + 38+20}" font-family="Helvetica, Arial, sans-serif" font-size="12" font-weight="bold"  text-anchor="middle" fill="#111">Step:{title}</text>')
  
    # Arrow marker
    svg_elements.append('''<defs>
      <marker id="arrowhead" orient="auto" markerWidth="8" markerHeight="8" refX="7" refY="4">
        <path d="M0,0 L8,4 L0,8 z" fill="#111" />
      </marker>
    </defs>''')

    # Draw dashed downward arrow pointing to LRU slot center
    lx = start_x + lru_index * (slot_w + gap) + slot_w/2
    arrow_top_y = start_y - 40
    arrow_mid_y = start_y 
    svg_elements.append(f'<path d="M{lx},{arrow_top_y} L{lx},{arrow_mid_y}" stroke="#111" stroke-width="3" stroke-dasharray="6 6" fill="none" marker-end="url(#arrowhead)"/>')
    svg_elements.append(f'<text x="{lx}" y="{arrow_top_y - 15}" font-family="Helvetica, Arial, sans-serif"   font-size="14" text-anchor="middle" fill="#111">LRU</text>')

    svg_elements.append('</svg>')
    svg_content = "\n".join(svg_elements)

    path = out_dir / f"lru_frame_{i}.svg"
    path.write_text(svg_content, encoding="utf-8")
    paths.append(path.as_posix())

print("Saved SVG files:")
for p in paths:
    print(p)

# Provide one combined path as requested by developer note (original uploaded file path)
print("\nOriginal generated SVG (embedded raster) from earlier step: /mnt/data/lru_frames.svg")

