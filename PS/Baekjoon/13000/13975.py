from heapq import heappop, heappush, heapify

T = int(input())
for i in range(T):
    N = int(input())
    arr = list(map(int, input().split()))

    res = 0
    heapify(arr)

    while len(arr) > 1:
        A, B = heappop(arr), heappop(arr)
        res += A + B
        heappush(arr, A + B)

    print(res)
