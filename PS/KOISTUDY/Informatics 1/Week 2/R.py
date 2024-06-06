A, B = map(int, input().split())
K = A * B

if K % 2:
    print(K // 2 + 1)
else:
    print(K // 2)
