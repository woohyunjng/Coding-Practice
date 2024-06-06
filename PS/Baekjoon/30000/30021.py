N = int(input())
if N == 1:
    print("YES")
    print(1)
elif N == 2:
    print("NO")
else:
    dp = [[] for j in range(3)]
    dp.append([1, 3, 2])
    for i in range(4, N + 1):
        dp.append(dp[-1] + [i])

    print("YES")
    print(" ".join(map(str, dp[N])))
