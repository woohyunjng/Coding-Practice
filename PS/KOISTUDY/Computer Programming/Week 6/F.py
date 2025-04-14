import sys

sys.setrecursionlimit(1 << 20)
input = sys.stdin.readline

MAX = 100001

A = [0] * MAX
B = [0] * MAX
V = [0] * MAX
K = [0] * MAX

ans = 1


def dnc(fs, fe, ps, pe):
    global ans
    if fs >= fe or ps >= pe:
        return

    X = A[fs]

    if V[A[fs + 1]] == V[X] - 1:
        dnc(fs + 1, fe, ps, pe - 1)
        ans <<= 1
    else:
        dnc(fs + 1, K[B[pe - 1]], ps, V[A[fs + 1]])
        dnc(K[B[pe - 1]], fe, V[A[fs + 1]] + 1, pe - 1)


N = int(input())

A[:N] = list(map(int, input().split()))
B[:N] = list(map(int, input().split()))

for i in range(N):
    K[A[i]] = i
for i in range(N):
    V[B[i]] = i

dnc(0, N - 1, 0, N - 1)
print(ans)
