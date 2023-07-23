N = int(input())
op = list(map(int, input().split()))

M = int(input())
arr = []

for i in range(M):
    arr.append(int(input()))


def get(X, Y, A):
    if len(A) == 1:
        res = min(abs(X - A[0]), abs(Y - A[0]))
    else:
        res = min(get(A[0], Y, A[1:]) + abs(X - A[0]), get(X, A[0], A[1:]) + abs(Y - A[0]))

    return res


print(get(*op, arr))
