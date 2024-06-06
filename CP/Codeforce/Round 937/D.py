# 100 (0:13)

nmlist = [
    11,
    101,
    111,
    1001,
    1011,
    1101,
    1111,
    10001,
    10011,
    10101,
    10111,
    11001,
    11011,
    11101,
    11111,
]

dp = [False for i in range(10**5 + 1)]
for i in range(10**5 + 1):
    while not i % 10:
        i //= 10

    if i in nmlist:
        dp[i] = True
    else:
        for j in nmlist:
            if not i % j and dp[i // j]:
                dp[i] = True

T = int(input())
for i in range(T):
    N = int(input())
    print("YES" if dp[N] else "NO")
