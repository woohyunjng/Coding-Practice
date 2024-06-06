N, K = map(int, input().split())
arr = list(map(int, input().split()))

mx = max(arr)
for i in range(N):
    arr[i] = mx - arr[i]

mx = max(arr)
if not K % 2:
    for i in range(N):
        arr[i] = mx - arr[i]
print(" ".join(map(str, arr)))
