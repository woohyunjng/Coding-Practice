from sys import stdin

T = int(stdin.readline())
for t in range(T):
    N = int(stdin.readline())
    arr = list(map(int, stdin.readline().rstrip().split()))

    mn = 10**10
    for i in range(N - 1):
        mn = min(mn, max(arr[i], arr[i + 1]))
    print(mn - 1)
