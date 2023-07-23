from collections import deque

T = int(input())
for i in range(T):
    A, B = map(int, input().split())
    dp = ["" for i in range(10000)]
    q = deque([A])

    while len(q):
        p = q.popleft()
        go = [
            ((p % 1000) * 10 + p // 1000, "L"),
            ((p % 10) * 1000 + p // 10, "R"),
            (p - 1 if p > 0 else 9999, "S"),
            (p * 2 % 10000, "D"),
        ]

        for x, y in go:
            if x == A:
                continue

            if dp[x] != "":
                continue

            dp[x] = dp[p] + y
            q.append(x)

            if x == B:
                break

    print(dp[B])
