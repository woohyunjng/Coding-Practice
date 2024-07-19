from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N = int(input())
    arr = [0] + list(map(int, input().rstrip().split()))
    go = [0 for i in range(N + 1)]
    group = [[] for i in range(N + 1)]

    cur = 1
    for i in range(1, N + 1):
        if go[i]:
            continue
        j = i
        if arr[j] == j:
            go[j] = cur
            group[cur].append(j)
            cur += 1
            continue
        while arr[j] != j and not go[j]:
            go[j] = cur
            group[cur].append(j)
            j = arr[j]
        cur += 1

    K = cur - 1
    cur = 0

    for i in range(1, K + 1):
        cur += len(group[i]) - 1

    res = 100000000000000000
    for i in range(1, N):
        K = cur
        if go[i + 1] == go[i]:
            K -= 1
        elif go[i + 1] != go[i]:
            K += 1
        res = min(res, K)

    print(res)
