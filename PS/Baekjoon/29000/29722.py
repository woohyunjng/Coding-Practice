A, B, C = map(int, input().split("-"))
N = int(input())

C += N

B += (C - 1) // 30
C = (C - 1) % 30 + 1

A += (B - 1) // 12
B = (B - 1) % 12 + 1

print(f"{A}-{str(B).zfill(2)}-{str(C).zfill(2)}")
