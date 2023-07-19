N, M, B = map(int, input().split())
arr = []

for i in range(N):
    for j in map(int, input().split()):
        arr.append(j)

arr = list(sorted(arr, reverse=True))

mn, h = 1000000000000000000000000000000000000000000000000000000000000000000, -1
for k in range(257):
    block, time, check = B, 0, False
    for i in range(N * M):
        if arr[i] > k:
            block += arr[i] - k
            time += (arr[i] - k) * 2
        else:
            block -= k - arr[i]
            if block < 0:
                check = True
                break
            time += k - arr[i]
    if check:
        continue

    if mn >= time:
        mn = time
        h = k

print(mn, h)
