N = int(input())
X, Y, R = map(int, input().split())
A, B = 0, 0

for i in range(N):
    T = int(input())
    if X - R < T < X + R:
        A += 1
    elif T == X - R or T == X + R:
        B += 1

print(A, B)
