N, K = map(int, input().split())
A, res = [], 0

for i in range(N):
    A.append(int(input()))

for i in range(N - 1, -1, -1):
    if A[i] > K:
        continue

    res += K // A[i]
    K -= K // A[i] * A[i]

print(res)
