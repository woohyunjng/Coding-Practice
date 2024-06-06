from heapq import heappop, heappush

N = int(input())
if not N:
    print(0)
    exit()

arr = []

for i in range(N):
    p, d = map(int, input().split())
    arr.append((p, d))

arr = list(sorted(arr, reverse=True, key=lambda x: x[1]))
mx = arr[0][1]
q, j = [], 0
res = 0

for i in range(mx, 0, -1):
    while j < N and arr[j][1] == i:
        heappush(q, -arr[j][0])
        j += 1
    if len(q):
        res += -heappop(q)

print(res)
