N, A, B = map(int, input().split())

X, Y = 1, 1

for i in range(N):
    X += A
    Y += B
    if X < Y:
        X, Y = Y, X
    elif X == Y:
        Y -= 1

print(X, Y)
