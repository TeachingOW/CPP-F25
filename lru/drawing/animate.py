import os

# Paths
base = "."
frames = [f"lru_frame_{i}.svg" for i in range(1,8)]
frame_svgs = []

for f in frames:
    path = os.path.join(base, f)
    with open(path, "r") as fp:
        frame_svgs.append(fp.read())

# Extract inner SVG content: remove outer <svg> ... </svg>
import re
inner = []
for svg in frame_svgs:
    content = re.sub(r"<svg[^>]*>", "", svg)
    content = re.sub(r"</svg>", "", content)
    inner.append(content.strip())

animated = ['<svg width="600" height="200" viewBox="0 0 600 240" xmlns="http://www.w3.org/2000/svg"> xmlns:xlink="http://www.w3.org/1999/xlink"']

for i, content in enumerate(inner, start=1):
    animated.append(f'<g id="frame{i}" visibility="{"visible" if i==1 else "hidden"}">{content}</g>')

# Add animations
for i in range(1,8):
    next_begin = "0s" if i == 1 else f"frame{i-1}start.end"
    animated.append(
        f'<set xlink:href="#frame{i}" attributeName="visibility" to="visible" '
        f'begin="{next_begin}" dur="1s" fill="remove" id="frame{i}start"/>'
    )
    animated.append(
        f'<set xlink:href="#frame{i}" attributeName="visibility" to="hidden" '
        f'begin="frame{i}start.end" />'
    )

animated.append("</svg>")
output_path = os.path.join(base, "lru_animation.svg")
with open(output_path, "w") as fp:
    fp.write("\n".join(animated))

output_path
