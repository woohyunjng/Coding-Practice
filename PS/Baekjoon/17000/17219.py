from sys import stdin

N, M = map(int, stdin.readline().rstrip().split())
arr = {}

for i in range(N):
    s, pw = stdin.readline().rstrip().split()
    arr[s] = pw

for i in range(M):
    s = stdin.readline().rstrip()
    print(arr[s])
