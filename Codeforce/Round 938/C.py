# 100 (0:15)

from collections import deque

T = int(input())
for t in range(T):
    N, K = map(int, input().split())
    arr = deque(map(int, input().split()))
    left, right = K - K // 2, K // 2

    res = 0
    while left and arr:
        if arr[0] <= left:
            left -= arr[0]
            res += 1
            arr.popleft()
        else:
            arr.appendleft(arr.popleft() - left)
            left = 0

    while right and arr:
        if arr[-1] <= right:
            right -= arr[-1]
            res += 1
            arr.pop()
        else:
            arr.append(arr.pop() - right)
            right = 0

    print(res)
