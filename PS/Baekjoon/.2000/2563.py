N = int(input())
arr = []

for i in range(N):
    arr.append(list(map(int, input().split())))

res = 0
for i in range(1, 101):
    for j in range(1, 101):
        for k in arr:
            if k[0] + 1 <= i <= k[0] + 10 and k[1] + 1 <= j <= k[1] + 10:
                res += 1
                break

print(res)
