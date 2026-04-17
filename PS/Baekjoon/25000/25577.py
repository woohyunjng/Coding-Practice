N = int(input())
A = list(map(int, input().split()))

go = {}
B = list(sorted(A))
pl = [0 for i in range(N)]

for i in range(N):
    go[B[i]] = i

for i in range(N):
    A[i] = go[A[i]]
    pl[A[i]] = i

res = 0
for i in range(N):
    if A[i] == i:
        continue

    pl[A[i]], A[pl[i]], A[i] = pl[i], A[i], i
    res += 1

print(res)
