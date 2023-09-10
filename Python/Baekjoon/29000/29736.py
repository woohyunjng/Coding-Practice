A, B = map(int, input().split())
K, X = map(int, input().split())

x = set([i for i in range(A, B + 1)])
y = set([i for i in range(K - X, K + X + 1)])

res = len(x & y)
print(res if res else "IMPOSSIBLE")
