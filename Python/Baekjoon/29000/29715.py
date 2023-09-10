from math import comb, factorial

N, M = map(int, input().split())
X, Y = map(int, input().split())
S, T = 0, N - M

for i in range(M):
    A, B = map(int, input().split())
    if not A:
        S += 1

res = comb(9 - M, T) * factorial(S + T)
time = (res - 1) // 3 * Y + res * X
print(time)
