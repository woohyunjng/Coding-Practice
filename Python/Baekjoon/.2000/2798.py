from itertools import combinations

N, M = map(int, input().split())
mx = -1

card = list(map(int, input().split()))

for i, j, k in combinations(card, 3):
    sm = i + j + k
    if sm <= M:
        mx = max(sm, mx)

print(mx)
