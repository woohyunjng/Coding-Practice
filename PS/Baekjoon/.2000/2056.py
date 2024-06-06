from collections import deque

N = int(input())
time = [0 for i in range(N)]
after = [[] for i in range(N)]
in_degree = [0 for i in range(N)]

for i in range(N):
    a = list(map(int, input().split()))
    time[i] = a[0]
    in_degree[i] = a[1]

    for j in a[2:]:
        after[j - 1].append(i)

dp = [0 for i in range(N)]
q = deque([])

for i in range(N):
    if not in_degree[i]:
        q.append(i)

while len(q):
    p = q.popleft()
    dp[p] += time[p]

    for i in after[p]:
        in_degree[i] -= 1
        dp[i] = max(dp[i], dp[p])
        if not in_degree[i]:
            q.append(i)

print(max(dp))
