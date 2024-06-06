A, B, N = map(int, input().split())
A, B = max(A, B), min(A, B)
res = 0

while A <= N:
    A, B = A + B, A
    res += 1

print(res)
