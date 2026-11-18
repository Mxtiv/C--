# Rebuilds everything that is derived from the //@ lines in 3_BUILDING_BLOCKS/*.cpp:
#   - the block catalog tables in README.md and 3_BUILDING_BLOCKS/README.md
#   - the line numbers of every [ID](...cpp#Lnn) link in every .md file of the repo
#   - the VS Code snippets file .vscode/inf04_blocks.code-snippets
# Run after changing a building block:  python 9_SELF_TESTS/rebuild_block_catalog.py
# (NOT needed at the exam.)
import html
import json
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
BLOCKS = REPO / '3_BUILDING_BLOCKS'
TITLES = {
    '01_input_output.cpp': 'Input / output',
    '02_random.cpp': 'Random numbers',
    '03_arrays.cpp': 'Arrays',
    '04_sorting.cpp': 'Sorting',
    '05_numbers.cpp': 'Number algorithms',
    '06_strings.cpp': 'Strings',
    '07_pesel.cpp': 'PESEL',
    '08_classes.cpp': 'Classes',
    '09_files.cpp': 'Files',
    '10_exceptions.cpp': 'Exceptions',
    '11_vector.cpp': 'vector',
    '12_templates.cpp': 'Templates',
}
NAME_RE = re.compile(r'^(?:class|struct)\s+(\w+)|^(?!template\b|return\b|else\b|if\b|for\b|while\b)[A-Za-z_][\w<>:,\s\*&]*?\b(\w+)\s*\(')


def read_text(path):
    return path.read_text(encoding='utf-8-sig')


def parse_blocks():
    blocks = []
    for f in sorted(BLOCKS.glob('[0-9][0-9]_*.cpp')):
        if f.name not in TITLES:
            continue
        lines = read_text(f).replace('\r\n', '\n').split('\n')
        starts = [i for i, l in enumerate(lines) if l.startswith('//@ ')]
        for k, i in enumerate(starts):
            parts = [p.strip() for p in lines[i][4:].split('|')]
            ident, desc = parts[0], parts[1]
            needs = parts[2] if len(parts) > 2 else '-'
            end = starts[k + 1] if k + 1 < len(starts) else len(lines)
            body = lines[i + 1:end]
            for j, l in enumerate(body):                  # last block ends at the DEMO section
                if l.startswith('// ====') or l.startswith('int main('):
                    body = body[:j]
                    break
            while body and body[-1].strip() == '':
                body.pop()
            names = []
            for l in body:
                m = NAME_RE.match(l)
                if m and '::' not in l.split('(')[0]:              # skip Klasa::metoda(...) definitions
                    n = m.group(1) or m.group(2)
                    if n not in names and n != 'main':
                        names.append(n)
            blocks.append({'id': ident, 'desc': desc, 'needs': needs, 'file': f.name,
                           'line': i + 1, 'body': body, 'names': names})
    return blocks


def table(blocks, prefix):
    out = []
    for fname, title in TITLES.items():
        rows = [b for b in blocks if b['file'] == fname]
        if not rows:
            continue
        out.append(f'### {title} - [{fname}]({prefix}{fname})')
        out.append('')
        out.append('| ID | Name | What it does | Needs |')
        out.append('|---|---|---|---|')
        for b in rows:
            names = ', '.join(f'`{n}`' for n in b['names'])
            needs = '' if b['needs'] == '-' else html.escape(b['needs'], quote=False)
            out.append(f"| [{b['id']}]({prefix}{fname}#L{b['line']}) | {names} | {html.escape(b['desc'], quote=False)} | {needs} |")
        out.append('')
    return '\n'.join(out)


def replace_section(text, start_marker, end_marker, new_body):
    s = text.index(start_marker)
    s = text.index('### ', s)
    e = text.index(end_marker, s) if end_marker else len(text)
    return text[:s] + new_body + ('\n' if end_marker else '') + text[e:]


def main():
    blocks = parse_blocks()
    by_id = {b['id']: b for b in blocks}
    n = len(blocks)

    # 1. catalogs
    readme = REPO / 'README.md'
    t = read_text(readme)
    t = replace_section(t, '## Building blocks - full catalog', '## More', table(blocks, '3_BUILDING_BLOCKS/'))
    t = re.sub(r'\d+ (paste-ready|blocks)', lambda m: f'{n} {m.group(1)}', t)
    readme.write_text(t, encoding='utf-8')

    breadme = BLOCKS / 'README.md'
    t = read_text(breadme)
    t = re.sub(r'## Catalog \(\d+ blocks\)', f'## Catalog ({n} blocks)', t)
    t = replace_section(t, '## Catalog (', None, table(blocks, ''))
    breadme.write_text(t, encoding='utf-8')

    # 2. line numbers of every block link in every .md
    link = re.compile(r'\[([A-Z]+-\d+)\]\(([^)\s#]*?)(\d\d_[a-z_]+\.cpp)#L\d+\)')
    broken = []
    for md in REPO.rglob('*.md'):
        if '.git' in md.parts:
            continue
        t = read_text(md)

        def fix(m):
            b = by_id.get(m.group(1))
            if not b:
                broken.append(f'{md.relative_to(REPO)}: {m.group(1)} no longer exists')
                return m.group(0)
            return f"[{b['id']}]({m.group(2)}{b['file']}#L{b['line']})"
        new = link.sub(fix, t)
        if new != t:
            md.write_text(new, encoding='utf-8')

    # 3. VS Code snippets
    snippets = {}
    for b in blocks:
        name = b['names'][0] if b['names'] else b['id']
        snippets[f"{b['id']} {name}"] = {
            'body': [l.replace('\\', '\\\\').replace('$', '\\$') for l in b['body']],
            'description': f"[{b['id']}] {b['desc']}",
            'prefix': [b['id'].lower().replace('-', '')] + b['names'],
            'scope': 'cpp',
        }
    (REPO / '.vscode' / 'inf04_blocks.code-snippets').write_text(
        json.dumps(snippets, indent=3, sort_keys=True, ensure_ascii=False) + '\n', encoding='utf-8')

    print(f'{n} blocks, catalogs + snippets rebuilt')
    for b in blocks:
        if not b['names']:
            print(f"  warning: no function/class name found in {b['id']}")
    for x in broken:
        print('  BROKEN LINK ' + x)
    return 1 if broken else 0


if __name__ == '__main__':
    sys.exit(main())
