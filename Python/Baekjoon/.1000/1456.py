A, B = map(int, input().split())
p = [True for i in range(round(B ** 0.5) + 1)]

for i in range(2, round(len(p) ** 0.5) + 1):
    if not p[i]:
        continue

    for j in range(i * 2, len(p), i):
        p[j] = False

res = 0
for i in range(2, len(p)):
    if not p[i]:
        continue

    j = 2
    while i ** j <= B:
        if i ** j >= A:
            res += 1
        j += 1

print(res)
