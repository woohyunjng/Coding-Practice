from sys import stdin

N, A, B = map(int, stdin.readline().rstrip().split())
res = 0

arr = []
for i in range(N):
    p, q = map(int, stdin.readline().rstrip().split())
    res += p
    arr.append(q - p)

arr = list(sorted(arr))[:B]
print(res + sum(arr))
