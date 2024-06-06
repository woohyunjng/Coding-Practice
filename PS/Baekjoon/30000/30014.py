from collections import deque

N = int(input())
P = list(map(int, input().split()))
P = list(sorted(P))

arr = deque([])
for i in range(N):
    if i % 2:
        arr.append(P[i])
    else:
        arr.appendleft(P[i])

res = 0
for i in range(N - 1):
    res += arr[i] * arr[i + 1]
res += arr[0] * arr[N - 1]

print(res)
print(*arr)
