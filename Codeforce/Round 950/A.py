from sys import stdin

T = int(stdin.readline())
for t in range(T):
    N, M = map(int, stdin.readline().rstrip().split())
    A = stdin.readline().rstrip()

    count = [0 for i in range(7)]
    for i in A:
        count[ord(i) - 65] += 1
    res = 0
    for i in range(7):
        if count[i] < M:
            res += M - count[i]
    print(res)
