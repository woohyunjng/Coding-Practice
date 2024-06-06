N, M = map(int, input().split())

res = 0
for i in range(N + M + 1):
    res += i + 1
    if i > N:
        res -= i - N
    if i > M:
        res -= i - M

print(res)
