N = int(input())
A = list(sorted(map(int, input().split())))
B = list(sorted(map(int, input().split()), reverse=True))

res = 0
for i in range(N):
    res += A[i] * B[i]

print(res)
