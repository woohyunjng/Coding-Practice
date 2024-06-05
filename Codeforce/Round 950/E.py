from sys import stdin

T = int(stdin.readline())
for t in range(T):
    N, M = map(int, stdin.readline().rstrip().split())
    A = []
    B = []

    row_A, row_B, col_A, col_B = [], [], [[] for i in range(M)], [[] for i in range(M)]

    for i in range(N):
        A.append(list(map(int, stdin.readline().rstrip().split())))
        row_A.append("".join(map(str, sorted(A[i]))))
        for j in range(M):
            col_A[j].append(A[i][j])

    for i in range(N):
        B.append(list(map(int, stdin.readline().rstrip().split())))
        row_B.append("".join(map(str, sorted(B[i]))))
        for j in range(M):
            col_B[j].append(B[i][j])

    row_A, row_B = set(row_A), set(row_B)
    for i in range(M):
        col_A[i] = "".join(map(str, sorted(col_A[i])))
        col_B[i] = "".join(map(str, sorted(col_B[i])))
    col_A, col_B = set(col_A), set(col_B)

    res = row_A == row_B and col_A == col_B
    print("YES" if res else "NO")
