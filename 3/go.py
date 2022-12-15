from pathlib import Path
import sys
import string
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--part', default=1)
parser.add_argument('--input', default='smol.txt')
args = parser.parse_args()
INPUT_PATH: Path = Path(args.input)

def main(input_path: Path, part : int): 
    ans = 0
    m = list(zip(list(string.ascii_letters), range(1,53)))
    dct = {i[0] : i[1] for i in m}
    with open(input_path) as f:
        lines = f.read().split("\n")
        if (part == 1): 
            # PART 1
            for line in lines:
                p1, p2 = line[:len(line) // 2], line[len(line) // 2:]
                common_chars = set(p1).intersection(p2)
                for c in common_chars: 
                    ans += dct[c]
                ans += sum(dct[c] for c in common_chars)
        else: 
            # PART 2
            groupList = [lines[i:i+3] for i in range(0, len(lines), 3)]
            for g in groupList:
                p1, p2, p3 = g
                common_chars = set(p1).intersection(set(p2)).intersection(p3)
                ans += sum(dct[c] for c in common_chars)
    print(f"Sol for part {args.part} = ", ans)
    
if __name__ == "__main__": 
    sys.exit(main(INPUT_PATH, part=args.part))
 