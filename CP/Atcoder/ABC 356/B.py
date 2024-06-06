from sys import stdin

N, M = map(int, stdin.readline().rstrip().split())
A = list(map(int, stdin.readline().rstrip().split()))
arr = [0 for i in range(M)]
for i in range(N):
    X = list(map(int, stdin.readline().rstrip().split()))
    for j in range(M):
        arr[j] += X[j]

res = True
for i in range(M):
    if arr[i] < A[i]:
        res = False
print("Yes" if res else "No")
