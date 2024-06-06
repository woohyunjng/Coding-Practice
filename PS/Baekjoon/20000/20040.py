from sys import stdin

N, M = map(int, stdin.readline().rstrip().split())
arr = [i for i in range(N)]


def find(i):
    if arr[i] != i:
        arr[i] = find(arr[i])
    return arr[i]


res = 0
for i in range(M):
    A, B = map(int, stdin.readline().rstrip().split())
    a, b = find(A), find(B)

    if a == b:
        if not res:
            res = i + 1
    else:
        arr[max(a, b)] = min(a, b)

print(res)
