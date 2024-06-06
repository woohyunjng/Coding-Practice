from collections import defaultdict

N, P, Q = map(int, input().split())
memo = defaultdict(int)
memo[0] = 1


def dp(A):
    if memo[A]:
        return memo[A]

    memo[A] = dp(A // P) + dp(A // Q)
    return memo[A]


print(dp(N))
