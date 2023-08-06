from bisect import bisect_left

N = int(input())
A = list(map(int, input().split()))
X, res = [], 0


for i in A:
    if len(X) == 0 or X[-1] < i:
        X.append(i)
        res += 1
    else:
        X[bisect_left(X, i)] = i

print(N - res)
