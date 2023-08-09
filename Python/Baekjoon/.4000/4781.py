while True:
    N, M = input().split()
    N, M = int(N), round(float(M) * 100)
    if not N * M:
        break

    arr = [(0, 0)]
    for i in range(N):
        c, p = input().split()
        arr.append((int(c), round(float(p) * 100)))

    dp = [0 for j in range(M + 1)]
    for i in range(1, N + 1):
        for j in range(M + 1):
            if j < arr[i][1]:
                dp[j] = dp[j]
            else:
                dp[j] = max(dp[j], dp[j - arr[i][1]] + arr[i][0])

    print(max(dp))
