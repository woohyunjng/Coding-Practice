P = int(input())
sw, em, ai, no = 0, 0, 0, 0

for i in range(P):
    G, C, N = map(int, input().split())
    if G <= 1:
        no += 1
        continue

    if C == 1 or C == 2:
        sw += 1
    elif C == 3:
        em += 1
    else:
        ai += 1

print(sw)
print(em)
print(ai)
print(no)
