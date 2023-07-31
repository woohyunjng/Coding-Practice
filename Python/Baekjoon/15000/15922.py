from sys import stdin

N = int(stdin.readline().rstrip())
res = 0
start, end = 0, 0

for i in range(N):
    x, y = map(int, stdin.readline().rstrip().split())
    if not i:
        start, end = x, y
        continue

    if x <= end:
        end = max(end, y)
    else:
        res += end - start
        start = x
        end = y

print(res + end - start)
