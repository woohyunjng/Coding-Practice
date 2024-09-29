A, B = map(int, input().split())
X, Y = map(int, input().split())

if A != 0 and B != 0:
    print(2)
elif A == 0:
    if X == 0 and Y < B:
        print(3)
    else:
        print(1)
elif B == 0:
    if Y == 0 and X < A:
        print(3)
    else:
        print(1)
