from bisect import bisect_left

N = input()
A = list(map(int, input().split()))
X, Y, Z = [], [], []


for i in A:
    if len(X) == 0 or X[-1] < i:
        X.append(i)
        Y.append(len(X) - 1)
    else:
        j = bisect_left(X, i)
        X[j] = i
        Y.append(j)
    Z.append(i)

k = len(X) - 1
res = []
for i in range(len(Y) - 1, -1, -1):
    if Y[i] == k:
        k -= 1
        res.append(Z[i])

print(len(res))
print(*reversed(res))
