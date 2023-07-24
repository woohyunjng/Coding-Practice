from collections import deque, defaultdict

A, B = map(int, input().split())
dp = defaultdict(int)
q = deque([A])
dp[A] = 1

while len(q):
    p = q.popleft()
    if p == B:
        break

    if p * 10 + 1 <= B:
        dp[p * 10 + 1] = dp[p] + 1
        q.append(p * 10 + 1)
    if p * 2 <= B:
        dp[p * 2] = dp[p] + 1
        q.append(p * 2)

print(dp[B] if dp[B] else -1)
