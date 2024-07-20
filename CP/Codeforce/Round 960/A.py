from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N = int(input())
    arr = list(map(int, input().rstrip().split()))
    cnt = [0 for i in range(N + 1)]

    for i in arr:
        cnt[i] += 1

    res = False
    for i in cnt:
        if i % 2:
            res = True

    print("YES" if res else "NO")
