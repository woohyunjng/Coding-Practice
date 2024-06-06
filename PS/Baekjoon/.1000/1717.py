from sys import stdin, setrecursionlimit

setrecursionlimit(1000002)

N, M = map(int, stdin.readline().split())
arr = [i for i in range(N + 1)]


def find(i):
    if arr[i] != i:
        arr[i] = find(arr[i])
    return arr[i]


for i in range(M):
    x, y, z = map(int, stdin.readline().split())
    Y, Z = find(y), find(z)

    if not x:
        arr[max(Y, Z)] = min(Y, Z)
    else:
        print("YES" if Y == Z else "NO")
