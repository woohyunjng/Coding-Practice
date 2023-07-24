from itertools import permutations
from collections import defaultdict

N, M = map(int, input().split())
arr = list(sorted(map(int, input().split())))
check = defaultdict(bool)

for i in permutations(arr, M):
    S = " ".join(map(str, i))
    if not check[S]:
        check[S] = True
        print(S)
