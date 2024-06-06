from collections import deque

N, K = map(int, input().split())
q = deque([N])
dp = [1e9 for i in range(200001)]
dp[N] = 0

while len(q):
    p = q.popleft()
    if p == K:
        print(dp[K])
        break

    if 1 <= p <= 100000 and dp[2 * p] > dp[p]:
        dp[2 * p] = dp[p]
        q.append(2 * p)

    if p < 200000 and dp[p + 1] > dp[p] + 1:
        dp[p + 1] = dp[p] + 1
        q.append(p + 1)

    if p and dp[p - 1] > dp[p] + 1:
        dp[p - 1] = dp[p] + 1
        q.append(p - 1)
