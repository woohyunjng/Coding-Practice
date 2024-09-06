from itertools import combinations

N, M = map(int, input().split())
S = input()
res = []

for i in combinations(range(N), M):
    val = ""
    for j in range(N):
        if j not in i:
            val += S[j]
    res.append(val)

res = reversed(res)
for i in res:
    print(i)
