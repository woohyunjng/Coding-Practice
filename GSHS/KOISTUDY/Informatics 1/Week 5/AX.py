N = int(input())
P = list(sorted(map(int, input().split())))
M, K = map(int, input().split())
K //= M

res = 0
for i in range(N):
    for j in range(i + 1, N):
        for k in range(j + 1, N):
            if P[i] + P[j] + P[k] <= K:
                res += 1
print(res)
