N, K, T0 = map(int, input().split())
D = list(map(int, input().split()))

res = 0

for i in range(N):
    T0 = D[i] + K
    res += abs(T0 - K)

print(res)
