from sys import stdin

input = stdin.readline

N, T, P = map(int, input().rstrip().split())
arr = list(map(int, input().rstrip().split()))
arr = list(sorted(arr))

K = arr[-P]
if K >= T:
    res = 0
else:
    res = T - K

print(res)
