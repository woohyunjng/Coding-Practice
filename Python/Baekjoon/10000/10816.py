N = int(input())
A = map(int, input().split())
A = list(sorted(A))
B = [1]
C = [A[0]]

x, y = A[0], 0
for i in range(1, N):
    if A[i] != x:
        B.append(0)
        x = A[i]
        C.append(x)
    B[-1] += 1

M = int(input())
K = map(int, input().split())
for i in K:
    st, en, f = 0, len(C) - 1, False
    while st <= en:
        md = (st + en) // 2
        if C[md] == i:
            f = True
            print(B[md], end=" ")
            break
        elif C[md] > i:
            en = md - 1
        else:
            st = md + 1

    if not f:
        print(0, end=" ")
