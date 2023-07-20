t = int(input())
for i in range(t):
    n = int(input())
    arr = []

    for j in range(n):
        s, d, p = map(int, input().split())
        arr.append([s, s + d, p])

    arr = list(sorted(arr, key=lambda x: x[1]))
    dp = [0 for i in range(arr[-1][1] + 1)]

    last, bf = 0, 0
    for j in range(len(dp)):
        if j == arr[last][1]:
            while j == arr[last][1]:
                bf = max(bf, arr[last][2] + dp[arr[last][0]])
                dp[j] = bf
                last += 1
                if last >= n:
                    break
        else:
            dp[j] = bf

    print(dp[-1])
