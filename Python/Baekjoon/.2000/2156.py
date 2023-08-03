N = int(input())
arr, dp = [0], [0]

for i in range(1, N + 1):
    arr.append(int(input()))

for i in range(1, N + 1):
    if i == 1:
        dp.append(arr[1])
    elif i == 2:
        dp.append(arr[1] + arr[2])
    else:
        dp.append(max(dp[-1], arr[i] + arr[i - 1] + dp[i - 3], arr[i] + dp[i - 2]))

print(dp[-1])
