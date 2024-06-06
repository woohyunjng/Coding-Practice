N, K = map(int, input().split())
sum_arr = [0]
arr = list(map(int, input().split()))

for i in arr:
    sum_arr.append(sum_arr[-1] + i)

mx = -10000000000000000
for i in range(1, N - K + 2):
    mx = max(mx, sum_arr[i + K - 1] - sum_arr[i - 1])

print(mx)
