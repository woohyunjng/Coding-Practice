N, K = map(int, input().split())
A = list(map(int, input().split()))

arr = [0 for i in range(K)]
for i in A:
    arr[i % K] += 1

res = (arr[0] + 1) * (arr[K // 2] + 1 if not K % 2 else 1)

for i in range(1, (K + 1) // 2):
    res = res * (2 ** arr[i] + 2 ** arr[K - i] - 1) % 1000000007

res -= N + 1

print(res % 1000000007)
