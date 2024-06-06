A, B, C, N = map(int, input().split())
for i in range(301):
    for j in range(301):
        for k in range(301):
            if A * i + B * j + C * k == N:
                print(1)
                exit()
print(0)
