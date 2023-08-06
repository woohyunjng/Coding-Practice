from heapq import heappop, heappush

N = int(input())
arr = []

for i in range(N):
    d, w = map(int, input().split())
    arr.append((d, w))

arr = list(sorted(arr, reverse=True))
mx = arr[0][0]

q = []
res, j = 0, 0

for i in range(mx, 0, -1):
    while j < N and arr[j][0] == i:
        heappush(q, -arr[j][1])
        j += 1

    if len(q):
        res += -heappop(q)

print(res)
