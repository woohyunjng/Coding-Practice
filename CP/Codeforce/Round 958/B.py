from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N = int(input())
    A = list(map(int, input().rstrip()))

    arr = []
    arr.append(A[0])
    for i in range(1, N):
        if arr[-1] == A[i] and A[i] == 0:
            continue
        arr.append(A[i])

    c0 = arr.count(0)
    c1 = arr.count(1)
    if c0 >= c1:
        print("No")
    else:
        print("Yes")
