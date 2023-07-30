from heapq import heappop, heappush

N = int(input())
arr = []

for i in range(N):
    heappush(arr, int(input()))

res = 0
while len(arr) > 1:
    A, B = heappop(arr), heappop(arr)
    heappush(arr, A + B)
    res += A + B

print(res)
