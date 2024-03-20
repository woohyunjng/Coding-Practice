from math import ceil

N, X = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

cur, res = 0, 0
for i, j in zip(A, B):
    cur += j
    if i > cur:
        res -= ceil((i - cur) / X)
        cur += ceil((i - cur) / X) * X
        if res < 0:
            res = -1
            break
    else:
        res += (cur - i) // X
        cur -= (cur - i) // X * X

print(res)
