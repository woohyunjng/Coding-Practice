from sys import stdin

N, M = map(int, stdin.readline().rstrip().split())
sum_arr = [[0] for i in range(N + 1)]
sum_arr[0] = [0 for i in range(N + 1)]

for i in range(1, N + 1):
    arr = list(map(int, input().split()))
    for j in range(N):
        sum_arr[i].append(sum_arr[i][-1] + sum_arr[i - 1][j + 1] - sum_arr[i - 1][j] + arr[j])

for k in range(M):
    x1, y1, x2, y2 = map(int, stdin.readline().rstrip().split())
    print(sum_arr[x2][y2] + sum_arr[x1 - 1][y1 - 1] - sum_arr[x2][y1 - 1] - sum_arr[x1 - 1][y2])
