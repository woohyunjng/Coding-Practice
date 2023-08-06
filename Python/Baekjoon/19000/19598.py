from heapq import heappush, heappop

N = int(input())
arr = []

for i in range(N):
    S, T = map(int, input().split())
    arr.append((S, T))

arr = list(sorted(arr))
q = []
heappush(q, arr[0][1])

for i in range(1, N):
    p = heappop(q)
    if arr[i][0] < p:
        heappush(q, arr[i][1])
        heappush(q, p)
    else:
        heappush(q, arr[i][1])

print(len(q))
