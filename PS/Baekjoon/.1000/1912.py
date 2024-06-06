N = int(input())
arr = list(map(int, input().split()))

dp = [arr[0]]
for i in range(1, N):
    dp.append(arr[i] + max(0, dp[-1]))

print(max(dp))
