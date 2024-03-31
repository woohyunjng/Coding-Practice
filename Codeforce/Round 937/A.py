# 100 (0:01)

T = int(input())
for i in range(T):
    A, B, C = map(int, input().split())
    if A < B and B < C:
        print("STAIR")
    elif A < B and B > C:
        print("PEAK")
    else:
        print("NONE")
