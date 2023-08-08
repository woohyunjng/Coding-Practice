# 100 / 100

from collections import deque

K = int(input())
X = list(map(int, input()))

mn = 1e9
for i in range(1, K + 1):
    if X[K - i] == 1:
        mn = K - i + 1
        break
else:
    mn = 0

two_mul = [1]
res = 1

for i in range(1, K + 1):
    if X[K - i] == 0:
        res += two_mul[i - 1]

    if res >= mn:
        break

    mn = min(mn, res + K - i)
    two_mul.append(2 * two_mul[-1])

print(mn)
