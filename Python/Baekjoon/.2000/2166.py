from math import floor


def triangle(A, B, C):
    return (A[0] * B[1] + B[0] * C[1] + C[0] * A[1] - A[1] * B[0] - B[1] * C[0] - C[1] * A[0]) / 2


def rround(N):
    if N - floor(N) < 0.5:
        return floor(N)
    else:
        return floor(N) + 1


N = int(input())
arr, res = [], 0

for i in range(N):
    arr.append(tuple(map(int, input().split())))

for i in range(1, N - 1):
    res += triangle(arr[0], arr[i], arr[i + 1])

print(rround(abs(res) * 10) / 10)
