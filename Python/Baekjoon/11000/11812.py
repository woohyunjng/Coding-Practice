from sys import stdin
from math import log, ceil

N, K, Q = map(int, stdin.readline().rstrip().split())
for i in range(Q):
    x, y = map(int, stdin.readline().rstrip().split())
    if K == 1:
        print(max(x, y) - min(x, y))
        continue

    depth_x, depth_y = (
        ceil(log((K - 1) * x + 1, K)) - 1,
        ceil(log((K - 1) * y + 1, K)) - 1,
    )
    if depth_x < depth_y:
        x, y = y, x
        depth_x, depth_y = depth_y, depth_x

    res = depth_x - depth_y
    while depth_x != depth_y:
        depth_x -= 1
        x = (x - 2) // K + 1

    while x != y:
        res += 2
        x = (x - 2) // K + 1
        y = (y - 2) // K + 1

    print(res)
