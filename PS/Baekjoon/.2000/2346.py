from collections import deque

N = int(input())
arr = list(map(int, input().split()))

dq = deque([i for i in range(1, N + 1)])
for i in arr:
    p = dq.popleft() - 1
    print(p + 1, end=" ")

    if not dq:
        break

    if arr[p] > 0:
        for j in range(arr[p] - 1):
            dq.append(dq.popleft())
    else:
        for j in range(-arr[p]):
            dq.appendleft(dq.pop())
