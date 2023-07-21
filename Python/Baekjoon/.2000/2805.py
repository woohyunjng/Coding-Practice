N, M = map(int, input().split())
arr = map(int, input().split())
arr = list(sorted(arr, reverse=True))
sm, res = arr[0], -1

for i in range(1, N):
    if sm - i * arr[i] >= M:
        res = (sm - M) // i
        break

    sm += arr[i]

if res == -1:
    res = (sm - M) // N

print(res)
