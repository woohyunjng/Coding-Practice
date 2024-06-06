from collections import deque

N, M = map(int, input().split())
ladder, snake = [0 for i in range(101)], [0 for i in range(101)]

for i in range(N):
    x, y = map(int, input().split())
    ladder[x] = y

for i in range(M):
    u, v = map(int, input().split())
    snake[u] = v

q = deque([1])
dp = [0 for i in range(101)]
dp[1] = 1

while len(q):
    p = q.popleft()
    for i in range(1, 7):
        s = p + i
        if s > 100 or dp[s]:
            continue

        if ladder[s]:
            s = ladder[s]
            if dp[s]:
                continue
        elif snake[s]:
            s = snake[s]
            if dp[s]:
                continue
        else:
            dp[s] = dp[p] + 1

        dp[s] = dp[p] + 1
        q.append(s)

print(dp[100] - 1)
