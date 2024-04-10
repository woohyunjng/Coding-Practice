# 100 (0:02 +1)

T = int(input())
for t in range(T):
    N, A, B = map(int, input().split())
    if A * 2 <= B:
        print(A * N)
    else:
        if N % 2:
            print(N // 2 * B + A)
        else:
            print(N // 2 * B)
