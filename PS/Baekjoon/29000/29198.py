from sys import stdin
from string import ascii_uppercase

N, M, K = map(int, stdin.readline().rstrip().split())
S = []
arr = []

for i in range(N):
    S = stdin.readline().rstrip()

    res = 0
    for j in ascii_uppercase:
        res = res * 100 + S.count(j) + 2

    arr.append((res, S))

arr = list(sorted(arr, reverse=True))
res = ""
for i in range(K):
    res += arr[i][1]

res = "".join(list(sorted(res)))
print(res)
