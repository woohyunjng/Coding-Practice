A, B = map(int, input().split())
C = 0
if A % 2:
    C = B
A >>= 1
B <<= 1
while A:
    if A % 2:
        C += B
    A >>= 1
    B <<= 1
print(C)
