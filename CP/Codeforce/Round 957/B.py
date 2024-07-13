from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N, K = map(int, input().rstrip().split())
    arr = list(map(int, input().rstrip().split()))

    arr = list(sorted(arr))
    arr = arr[:-1]

    res = 0
    for i in arr:
        res += i * 2 - 1
    print(res)
