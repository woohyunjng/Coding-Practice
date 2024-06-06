N = int(input())
A = list(map(int, input().split()))
B = [0 for i in range(N)]

for i in range(N):
    B[A[i] - 1] = i
X = [0 for i in range(N)]

for i in A:
    if i != 1 and B[i - 2] < B[i - 1]:
        X[i - 1] = X[i - 2] + 1
    else:
        X[i - 1] += 1

print(N - max(X))
