from sys import stdin

N, K = map(int, stdin.readline().rstrip().split())
arr = list(map(int, stdin.readline().rstrip().split()))

sum_arr = [0]
for i in arr:
    sum_arr.append(sum_arr[-1] + i)
sum_arr = sum_arr[1:]

sum_arr = list(sorted(sum_arr, reverse=True))
res = 0

for i in range(K):
    res += sum_arr[i]

print(res)
