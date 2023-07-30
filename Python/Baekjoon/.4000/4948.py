from sys import stdin

arr = []
while True:
    N = int(stdin.readline().rstrip())
    if not N:
        break

    arr.append(N)

mx = max(arr) * 2
checked = [True for i in range(mx + 1)]
checked[1] = False

for i in range(2, int(mx**0.5) + 1):
    if not checked[i]:
        continue

    for j in range(i * 2, mx + 1, i):
        checked[j] = False

for i in arr:
    res = 0
    for j in range(i + 1, i * 2 + 1):
        if checked[j]:
            res += 1
    print(res)
