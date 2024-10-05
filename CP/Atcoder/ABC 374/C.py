N = int(input())
K = list(map(int, input().split()))

res = 1000000000

for i in range(1 << N):
    A, B = 0, 0
    for j in range(N):
        if i & (1 << j):
            A += K[j]
        else:
            B += K[j]
    res = min(res, max(A, B))

print(res)
