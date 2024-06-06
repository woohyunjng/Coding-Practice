from sys import stdin

T = int(stdin.readline())
for i in range(T):
    N = int(input())
    arr = list(map(lambda x: int(x) - 1, input().split()))
    checked = [False for i in range(N)]

    res = 0
    for i in range(N):
        if checked[i]:
            continue
        res += 1
        checked[i] = True
        j = arr[i]

        while not checked[j]:
            checked[j] = True
            j = arr[j]

    print(res)
