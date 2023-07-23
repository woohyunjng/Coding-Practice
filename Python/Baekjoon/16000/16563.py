N = int(input())
k = list(map(int, input().split()))

mx = max(k)
n = [True for i in range(mx + 1)]
p = [i for i in range(mx + 1)]

for i in range(2, round(mx**0.5) + 1):
    if not n[i]:
        continue
    for j in range(2 * i, mx + 1, i):
        n[j] = False
        if p[j] == j:
            p[j] = i

for i in k:
    while i > 1:
        print(p[i], end=" ")
        i //= p[i]
    print()
