from sys import stdin

N, R, Q = map(int, stdin.readline().rstrip().split())

arr = [[] for i in range(N + 1)]
checked = [False for i in range(N + 1)]
dp = [0 for i in range(N + 1)]

for i in range(N - 1):
    U, V = map(int, stdin.readline().rstrip().split())
    arr[U].append(V)
    arr[V].append(U)

i, q = 0, [R]
checked[R] = True

while i < len(q):
    p = q[i]
    for j in arr[p]:
        if not checked[j]:
            q.append(j)
            checked[j] = True
    i += 1

for i in q[::-1]:
    if not dp[i]:
        dp[i] = 1

    for j in arr[i]:
        dp[i] += dp[j]

for i in range(Q):
    U = int(stdin.readline())
    print(dp[U])
