A, B, C = map(int, input().split())
for i in range(A):
    for j in range(B):
        for k in range(C):
            print(i, j, k)
print(A * B * C)
