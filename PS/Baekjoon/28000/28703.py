N = int(input())
arr = list(map(int, input().split()))
mx = max(arr)

for i in range(N):
    while arr[i] * 2 < mx:
        arr[i] *= 2
arr = list(sorted(arr))

mn = arr[N - 1] - arr[0]
for i in range(1, N):
    mn = min(mn, 2 * arr[i - 1] - arr[i])

print(mn)
