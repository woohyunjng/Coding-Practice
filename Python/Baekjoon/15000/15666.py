from itertools import product
from collections import defaultdict

N, M = map(int, input().split())
arr = list(sorted(map(int, input().split())))
check = defaultdict(bool)

for i in product(*[arr for j in range(M)]):
    for j in range(1, len(i)):
        if i[j] < i[j - 1]:
            break
    else:
        S = " ".join(map(str, i))
        if not check[S]:
            check[S] = True
            print(S)
