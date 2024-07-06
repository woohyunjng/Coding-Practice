N, K = map(int, input().split())
arr = list(map(int, input().split()))
arr = list(sorted(arr))

res = 10000000000
for i in range(K + 1):
    res = min(res, arr[N - 1 - (K - i)] - arr[i])
print(res)
