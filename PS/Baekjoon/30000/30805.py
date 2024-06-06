from sys import stdin

N = int(stdin.readline())
A = list(map(int, stdin.readline().rstrip().split()))
M = int(stdin.readline())
B = list(map(int, stdin.readline().rstrip().split()))

res = []

for i in range(100, 0, -1):
    K = i in A and i in B
    while K:
        A = A[A.index(i) + 1 :]
        B = B[B.index(i) + 1 :]
        res.append(i)
        K = i in A and i in B

print(len(res))
if res:
    print(*res, sep=" ")
