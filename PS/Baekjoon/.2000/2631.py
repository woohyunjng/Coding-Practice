from bisect import bisect_left

N = int(input())
arr = []

for i in range(N):
    arr.append(int(input()))

X = []
for i in arr:
    if not X or X[-1] < i:
        X.append(i)
    else:
        X[bisect_left(X, i)] = i

print(N - len(X))
