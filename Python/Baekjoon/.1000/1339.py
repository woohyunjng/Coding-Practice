from collections import defaultdict

N = int(input())
S = defaultdict(int)

for i in range(N):
    X = input()
    for j in range(len(X) - 1, -1, -1):
        S[X[j]] += 10 ** (len(X) - 1 - j)

S = list(sorted(S.values()))
res = 0

for i in range(9, -1, -1):
    if not len(S):
        break
    res += S.pop() * i

print(res)
