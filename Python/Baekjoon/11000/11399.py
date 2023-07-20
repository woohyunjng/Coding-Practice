N = int(input())
arr = map(int, input().split())
arr = list(sorted(arr))

dp = [arr[0]]
for i in range(1, N):
    dp.append(dp[-1] + arr[i])

print(sum(dp))
