from heapq import heappop, heappush

N = int(input())
arr = []

for i in range(N):
    A, B = map(int, input().split())
    arr.append((A, B))

arr = list(sorted(arr))
hp = []
day = N
res = 0

while day:
    while arr and arr[-1][0] == day:
        heappush(hp, -arr[-1][1])
        arr.pop()
    if hp:
        res += -heappop(hp)
    day -= 1

print(res)
