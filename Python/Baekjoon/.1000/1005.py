from sys import stdin
from collections import deque

T = int(input())
for i in range(T):
    N, K = map(int, stdin.readline().rstrip().split())
    D = [0] + list(map(int, stdin.readline().rstrip().split()))

    arr = [[] for i in range(N + 1)]
    in_degree = [0 for i in range(N + 1)]

    for i in range(K):
        X, Y = map(int, stdin.readline().rstrip().split())
        arr[X].append(Y)
        in_degree[Y] += 1

    q = deque([])
    for i in range(1, N + 1):
        if not in_degree[i]:
            q.append(i)
    building_list = []

    while len(q):
        p = q.popleft()
        building_list.append(p)
        for i in arr[p]:
            in_degree[i] -= 1
            if not in_degree[i]:
                q.append(i)

    W = int(stdin.readline())
    dp = [0 for i in range(N + 1)]

    for i in building_list:
        dp[i] += D[i]
        for j in arr[i]:
            dp[j] = max(dp[j], dp[i])

    print(dp[W])
