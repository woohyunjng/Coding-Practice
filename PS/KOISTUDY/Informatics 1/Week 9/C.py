A, B = map(int, input().split())
while A:
    A, B = B % A, A
print(B)
