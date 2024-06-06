from collections import deque

N, S, E, M = map(int, input().split())
arr = []

for i in range(M):
    s, e, T = map(int, input().split())
    arr.append((s, e, T))

money = list(map(int, input().split()))

dp = [-1e15 for i in range(N)]
dp[S] = money[S]
q = deque([])

for i in range(N):
    for s, e, T in arr:
        if dp[s] != -1e15 and dp[e] < dp[s] - T + money[e]:
            dp[e] = dp[s] - T + money[e]
            if i == N - 1:
                q.append(e)

cycle_possible = False
checked = [False for i in range(N)]
for i in q:
    checked[i] = True

while len(q):
    p = q.popleft()
    if p == E:
        cycle_possible = True
        break

    for s, e, T in arr:
        if s != p or checked[e]:
            continue
        q.append(e)
        checked[e] = True

if dp[E] == -1e15:
    print("gg")
elif cycle_possible:
    print("Gee")
else:
    print(dp[E])
