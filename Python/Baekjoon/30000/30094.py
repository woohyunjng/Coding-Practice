from sys import stdin
from collections import defaultdict
from math import factorial

MOD = 998244353

N = int(stdin.readline())
arr = []
base, case = 0, 1

freq, checked = defaultdict(int), defaultdict(bool)

for i in range(N):
    c, a = map(int, stdin.readline().rstrip().split())
    arr.append((c - a, i + 1))
    freq[c - a] += 1
    base += (N - 1) * a

arr = list(sorted(arr))
mn, mx = base, base
for i in range(N):
    mn += (N - 1 - i) * arr[i][0]
    mx += i * arr[i][0]
    if not checked[arr[i][0]]:
        checked[arr[i][0]] = True
        case = case * factorial(freq[arr[i][0]]) % MOD

arr = [j for i, j in arr]
case %= MOD

print(mn, case)
print(" ".join(map(str, reversed(arr))))

print(mx, case)
print(" ".join(map(str, arr)))
