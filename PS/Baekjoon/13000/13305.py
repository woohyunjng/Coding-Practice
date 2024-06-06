N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

res, crnt = 0, 1e9
for i in range(N - 1):
    crnt = min(crnt, B[i])
    res += crnt * A[i]

print(res)
