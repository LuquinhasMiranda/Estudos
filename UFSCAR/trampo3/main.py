txt = input()

def find_wally(lines):
    i = 0
    while i < len(lines):
        line = lines[i].strip()
        horizontal = line.find('wally')
        if horizontal != -1:
            return (i+1, horizontal+1, 'horizontal')
        if i + 4 >= len(lines):
            i += 1
            continue
        ws = []
        for j in range(len(line)):
            if line[j] == 'w':
                ws.append(j)
        for w_idx in ws:
            if lines[i+1][w_idx] == 'a' and  \
                lines[i+2][w_idx] == 'l' and  \
                lines[i+3][w_idx] == 'l' and  \
                lines[i+4][w_idx] == 'y':
                return [i+1, w_idx+1, 'vertical']
        i += 1
        
with open(txt, 'r') as fd:
    lines = fd.readlines()
    ans = find_wally(lines)
    print(f'{ans[0]} {ans[1]} {ans[2]}')