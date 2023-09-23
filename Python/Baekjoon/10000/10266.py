from sys import stdin

N = int(stdin.readline())
A = list(sorted(list(map(int, stdin.readline().rstrip().split()))))
B = list(sorted(list(map(int, stdin.readline().rstrip().split()))))

pi_A, pi_B = [0 for i in range(N)], [0 for i in range(N)]
X, Y = [], []

for i in range(1, N):
    X.append(A[i] - A[i - 1])
    Y.append(B[i] - B[i - 1])
X.append(A[0] + 360000 - A[N - 1])
Y.append(B[0] + 360000 - B[N - 1])

x, y = 0, 0
for i in range(1, N):
    while x > 0 and X[i] != Y[x]:
        x = pi_A[x - 1]
    while y > 0 and Y[i] != X[y]:
        y = pi_B[y - 1]

    if X[i] == Y[x]:
        x += 1
        pi_A[i] = x
    if Y[i] == X[y]:
        y += 1
        pi_B[i] = y

print("possible" if pi_A[N - 1] + pi_B[N - 1] >= N else "impossible")
