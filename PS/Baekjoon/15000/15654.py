from itertools import permutations

N, M = map(int, input().split())
arr = list(sorted(map(int, input().split())))

for i in permutations(arr, M):
    print(" ".join(map(str, i)))
