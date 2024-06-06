N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

res = 0
for i in range(N):
    res += int(A[i] <= B[i])

print(res)
