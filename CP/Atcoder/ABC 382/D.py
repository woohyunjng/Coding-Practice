from itertools import combinations_with_replacement

N, M = map(int, input().split())
cnt = 0

res = []

for i in combinations_with_replacement(range(M % 10 if M % 10 != 0 else 10), N):
    cnt += 1
    res.append([])
    for j in range(N):
        res[-1].append(j * 10 + i[j] + 1)

print(cnt)
for i in res:
    print(*i)
