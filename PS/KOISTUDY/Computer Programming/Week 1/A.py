arr = list(map(int, input().split()))
res = 0

for i in arr:
    if i % 2:
        res += i

print(res if res > 0 else -1)
