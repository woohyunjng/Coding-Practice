from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N, K = map(int, input().split())
    arr = []
    res = 0

    for i in range(1, N):
        arr.append(i)
        arr.append(i)
    arr.append(N)

    while K:
        res += 1
        if K >= arr[-1]:
            K -= arr[-1]
            arr.pop()
        else:
            K = 0
    print(res)
