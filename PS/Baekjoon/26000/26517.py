K = int(input())
A, B, C, D = map(int, input().split())
X, Y = A * K + B, C * K + D
if X == Y:
    print("Yes", X)
else:
    print("No")
