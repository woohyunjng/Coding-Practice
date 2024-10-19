from sys import stdin

input = stdin.readline

N, C = map(int, input().split())
T = list(map(int, input().split()))

res, X = 1, T[0]
for i in range(1, N):
    if T[i] - X >= C:
        res += 1
        X = T[i]
print(res)
