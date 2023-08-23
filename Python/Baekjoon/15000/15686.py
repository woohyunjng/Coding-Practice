from itertools import combinations

N, M = map(int, input().split())
home = []
chick = []

for i in range(N):
    line = list(map(int, input().split()))
    for j in range(N):
        if line[j] == 1:
            home.append((i, j))
        elif line[j] == 2:
            chick.append((i, j))

res = 1e9
for c in combinations(chick, M):
    a = 0
    for x, y in home:
        b = 1e9
        for i, j in c:
            b = min(b, abs(x - i) + abs(y - j))
        a += b
    res = min(res, a)

print(res)
