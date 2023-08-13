from math import gcd

N, K = map(int, input().split())
L = len(str(N))

num, res = 0, -1

for i in range(1, K + 1):
    num = (num * 10**L + N) % K
    if not num:
        res = i
        break

print(res)
