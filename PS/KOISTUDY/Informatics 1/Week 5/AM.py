A, B = map(int, input().split())
A, B = max(A, B), min(A, B)

while A % B:
    A, B = B, A % B

print(B)
