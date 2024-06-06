from sys import stdin
from collections import defaultdict

N = int(stdin.readline())
arr = []

for i in range(N):
    C, S = map(int, stdin.readline().rstrip().split())
    arr.append((i, C, S))

arr = list(sorted(arr, key=lambda x: x[2]))
ball_sum = [0 for i in range(N + 1)]
res = [0 for i in range(N)]
sm = 0

size = defaultdict(int)
ball_size = [defaultdict(int) for i in range(N + 1)]

for i in range(N):
    sm += arr[i][2]
    ball_sum[arr[i][1]] += arr[i][2]

    size[arr[i][2]] += 1
    ball_size[arr[i][1]][arr[i][2]] += 1
    res[arr[i][0]] = (
        sm
        - size[arr[i][2]] * arr[i][2]
        - ball_sum[arr[i][1]]
        + ball_size[arr[i][1]][arr[i][2]] * arr[i][2]
    )

for i in range(N):
    print(res[i])
