from sys import stdin

N, M = map(int, stdin.readline().rstrip().split())
H = list(map(int, stdin.readline().rstrip().split()))

res = 0
for i in H:
    if i <= M:
        M -= i
        res += 1
    else:
        break
print(res)
