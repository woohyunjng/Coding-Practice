from sys import stdin

T = int(stdin.readline())
for t in range(T):
    N, F, K = map(int, stdin.readline().rstrip().split())
    arr = list(map(int, stdin.readline().rstrip().split()))
    A = arr[F - 1]

    arr = list(sorted(arr, reverse=True))
    first, end = -1, -1

    for i in range(N):
        if arr[i] != A:
            continue
        if first == -1:
            first = i
        end = i

    if end < K:
        print("YES")
    elif K <= first:
        print("NO")
    else:
        print("MAYBE")
