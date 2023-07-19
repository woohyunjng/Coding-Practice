from collections import deque

N, K = map(int, input().split())
a, b = deque(range(1, N + 1)), []

while len(a):
    for i in range(K - 1):
        a.append(a.popleft())
    b.append(a.popleft())

print("<", end="")
for i in range(N):
    if i < N - 1:
        print(b[i], end=", ")
    else:
        print(b[N - 1], end=">")
