N, K = map(int, input().split())
res = 1

for i in range(2, N + 1):
    res = (res + K - 1) % i + 1

print(res)
