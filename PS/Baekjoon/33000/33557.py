T = int(input())

for t in range(T):
    A, B = input().split()

    X = str(int(A) * int(B))
    Y = ""

    if len(A) < len(B):
        A, B = B, A
    for i in range(len(A) - len(B)):
        Y += A[i]
    A = A[len(A) - len(B) :]
    for i in range(len(A)):
        Y += str(int(A[i]) * int(B[i]))

    print(1 if X == Y else 0)
