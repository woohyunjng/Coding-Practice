N = int(input())
res = []

for i in range(N):
    arr = list(map(int, input().split()))
    res.append(["M", "D", "K", "G", "U"][arr.count(1)])

print(*res)
