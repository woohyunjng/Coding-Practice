from sys import stdin
from bisect import bisect_left, bisect_right

N, S, E = map(int, stdin.readline().rstrip().split())
start, end, mid = [], [], []

zer = False
for i in range(N):
    s, e = map(int, stdin.readline().rstrip().split())
    if e <= S or E <= s:
        continue

    if s <= S and e >= E:
        zer = True

    if s <= S:
        start.append(min(E, e))
    elif e >= E:
        end.append(max(S, s))
    else:
        mid.append((s, e))

if zer:
    print(0)
    exit()

start = list(sorted(start))
end = list(sorted(end))

res_1 = 10**10
for i in start:
    j = bisect_right(end, i)
    if j == 0:
        continue
    res_1 = min(res_1, i - end[j - 1])

res_2 = 10**10
for i, j in mid:
    a = bisect_left(start, i)
    b = bisect_right(end, j)
    if a == len(start):
        continue
    if b == 0:
        continue

    res_2 = min(res_2, start[a] - i + j - end[b - 1])

res = min(res_1, res_2)
print(res if res < 10**10 else -1)
