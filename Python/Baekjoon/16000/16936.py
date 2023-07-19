N = int(input())
A = list(map(int, input().split()))

mx = -1

for i in range(N):
    k, j = A[i], 0
    while k % 3 == 0:
        k //= 3
        j += 1

    A[i] = [A[i], j]
    mx = max(mx, j)

A = list(sorted(A, key=lambda x: x[1]))
B = [[A[N - 1][0]]]

for i in range(N - 2, -1, -1):
    if A[i][1] == mx:
        B[-1].append(A[i][0])
    else:
        mx -= 1
        B.append([A[i][0]])

for i in range(len(B)):
    B[i] = list(sorted(B[i]))
    for j in B[i]:
        print(j, end=" ")
