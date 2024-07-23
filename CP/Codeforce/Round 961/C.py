from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N = int(input())
    arr = list(map(int, input().split()))
    dp = [0 for i in range(N)]

    for i in range(1, N):
        A, B = arr[i - 1], arr[i]
        if A > B:
            if B == 1:
                print(-1)
                break
            while A > B:
                B = B**2
                dp[i] += 1
        else:
            if A == 1:
                continue
            while A**2 <= B:
                A = A**2
                dp[i] -= 1
    else:
        res = 0
        for i in range(1, N):
            if arr[i] == 1:
                continue
            if dp[i] > 0:
                res += dp[i]
                if i != N - 1:
                    dp[i + 1] += dp[i]
        print(res)
