from itertools import product

N, M = map(int, input().split())
arr = list(sorted(map(int, input().split())))

for i in product(*[arr for j in range(M)]):
    print(" ".join(map(str, i)))
