A, B = sorted(map(int, input().split()))
C, D = sorted(map(int, input().split()))
if C < A:
    A, B, C, D = C, D, A, B

print("cross" if C < B < D else "not cross")
