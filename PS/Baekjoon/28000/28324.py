N = int(input())
V = list(map(int, reversed(input().split())))

res, vl = 0, 0
for i in V:
    if i >= vl + 1:
        vl += 1
    else:
        vl = i

    res += vl

print(res)
