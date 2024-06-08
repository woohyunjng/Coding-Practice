S = input()
lw, up = 0, 0

for i in S:
    if i.upper() == i:
        up += 1
    else:
        lw += 1

if up > lw:
    print(S.upper())
else:
    print(S.lower())
