from sys import stdin
from collections import defaultdict

N = int(stdin.readline())
arr = list(map(int, stdin.readline().rstrip().split()))

icecream = defaultdict(int)
for i in arr:
    icecream[i] += 1

Q = int(stdin.readline())
for i in range(Q):
    A = list(map(int, stdin.readline().rstrip().split()))[1:]
    A_check = defaultdict(int)
    for j in A:
        A_check[j] += 1

    B = list(map(int, stdin.readline().rstrip().split()))[1:]
    B_check = defaultdict(int)
    for j in B:
        B_check[j] += 1

    if all([icecream[x] >= y for x, y in A_check.items()]):
        for x, y in A_check.items():
            icecream[x] -= y

        for x, y in B_check.items():
            icecream[x] += y

arr = []
for i, j in icecream.items():
    for k in range(j):
        arr.append(i)

print(len(arr))
print(" ".join(map(str, list(sorted(arr)))))
