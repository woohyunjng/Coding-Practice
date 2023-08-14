from math import lcm

N = int(input())
arr = list(map(lambda x: int(x) - 1, input().split()))

res = []
checked = [False for i in range(N)]

for i in range(N):
    if checked[i]:
        continue

    res.append(1)
    checked[i] = True
    j = arr[i]
    while not checked[j]:
        checked[j] = True
        j = arr[j]
        res[-1] += 1

print(lcm(*res))
