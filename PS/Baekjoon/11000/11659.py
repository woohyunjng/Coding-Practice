from sys import stdin

N, M = map(int, stdin.readline().rstrip().split())
arr = list(map(int, input().split()))
sum_arr = [0]

for i in range(1, N + 1):
    sum_arr.append(sum_arr[-1] + arr[i - 1])

for k in range(M):
    i, j = map(int, stdin.readline().rstrip().split())
    print(sum_arr[j] - sum_arr[i - 1])
