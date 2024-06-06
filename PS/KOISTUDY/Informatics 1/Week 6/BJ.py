N = int(input())
res = 0

for i in range(1, N):
    for j in range(i, N):
        if N < i + j * 2:
            continue
        if N >= (i + j) * 2:
            continue
        res += 1

print(res)
