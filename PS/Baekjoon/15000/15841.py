dp = [0, 1]

while True:
    N = int(input())
    if N == -1:
        break

    if N >= len(dp):
        while N >= len(dp):
            dp.append(dp[-1] + dp[-2])
    print(f"Hour {N}: {dp[N]} cow(s) affected")
