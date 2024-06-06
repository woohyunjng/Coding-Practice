d = int(input())
res = []

for i in range(12):
    for j in range(60):
        if abs(60 * i - 11 * j) in [2 * d, 720 - 2 * d]:
            res.append((i, j))

print(len(res))
for i, j in res:
    print(str(i).rjust(2, "0") + ":" + str(j).rjust(2, "0"))
