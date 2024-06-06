N, K = map(int, input().split())
price = [0, 1000, 1000, 2000, 3000, 3000, 6000, 6000]
count = [0 for i in range(8)]
res = 0

for i in range(N):
    line = list(map(int, input().split()))[1:]
    for j in line:
        count[j] += 1

for i in range(1, 8):
    if count[i] >= K:
        res += price[i] * N
print(res)
