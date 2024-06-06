from sys import stdin

N, M = map(int, stdin.readline().rstrip().split())
arr = [0 for i in range(N + 1)]
for i in range(M):
    k, s, e = map(int, stdin.readline().rstrip().split())
    if arr[k] <= s:
        arr[k] = e
        print("YES")
    else:
        print("NO")
