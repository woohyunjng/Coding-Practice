N, M, K = map(int, input().split())
arr = {}
sub = []

for i in range(N):
    A, B = input().split()
    arr[A] = int(B)
    sub.append((int(B), A))

default = 0
lst = []

for i in range(K):
    lst.append(input())
    default += arr[lst[-1]]

res = []
for i, j in sub:
    if j not in lst:
        res.append(i)
res = list(sorted(res))

if K != M:
    print(default + sum(res[: M - K]), default + sum(res[K - M :]))
else:
    print(default, default)
