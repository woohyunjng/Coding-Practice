from math import floor


def triangle(A, B, C):
    return (
        A[0] * B[1]
        + B[0] * C[1]
        + C[0] * A[1]
        - A[1] * B[0]
        - B[1] * C[0]
        - C[1] * A[0]
    ) / 2


N = int(input())
res = 0

for i in range(N):
    P = int(input())
    arr, S = [], 0

    for j in range(P):
        arr.append(tuple(map(int, input().split())))

    for j in range(1, P - 1):
        S += triangle(arr[0], arr[j], arr[j + 1])
    res += abs(S)


print(floor(res))
