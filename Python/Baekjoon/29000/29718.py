N, M = map(int, input().split())
arr = [0 for i in range(M)]

for i in range(N):
    line = list(map(int, input().split()))
    for j in range(M):
        arr[j] += line[j]

A = int(input())
sm, mx = 0, 0

for i in range(A):
    sm += arr[i]
mx = sm

for i in range(A, M):
    sm += arr[i] - arr[i - A]
    mx = max(sm, mx)

print(mx)
