from collections import defaultdict

N, M = map(int, input().split())
S = defaultdict(bool)

for i in range(N):
    X = input()
    S[X] = True

res = 0
for i in range(M):
    X = input()
    res += 1 if S[X] else 0

print(res)
