from itertools import combinations_with_replacement

N, M = map(int, input().split())
arr = list(sorted(map(int, input().split())))

for i in combinations_with_replacement(arr, M):
    for j in range(1, len(i)):
        if i[j] < i[j - 1]:
            break
    else:
        print(" ".join(map(str, i)))