from sys import stdin
from collections import defaultdict

N, K = map(int, stdin.readline().rstrip().split())
place = 0

checked_first = [defaultdict(bool) for i in range(N + 1)]
checked_second = [defaultdict(bool) for i in range(N + 1)]
arr = []

for i in range(K):
    X, Y = map(int, stdin.readline().rstrip().split())
    checked_first[X][Y] = True
    arr.append((X, Y))

for X, Y in arr:
    go = [(X + 2, Y), (X - 2, Y), (X, Y + 2), (X, Y - 2)]
    for x, y in go:
        if x > N or x <= 0 or y > N or y <= 0 or checked_first[x][y] or checked_second[x][y]:
            continue

        place += 1
        checked_second[x][y] = True

print(place)
