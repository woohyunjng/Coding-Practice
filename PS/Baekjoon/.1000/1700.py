from collections import deque

N, K = map(int, input().split())
arr = list(map(int, input().split()))

pos = [deque([]) for i in range(K + 1)]
for i in range(K):
    pos[arr[i]].append(i)

for i in range(K + 1):
    pos[i].append(K + 1)

cur = []
checked = [False for i in range(K + 1)]

res = 0

for i in arr:
    pos[i].popleft()
    if checked[i]:
        continue

    checked[i] = True
    if len(cur) < N:
        cur.append(i)
        continue

    lst, index = -1, -1
    for j in range(N):
        if pos[cur[j]][0] > lst:
            lst = pos[cur[j]][0]
            index = j

    checked[cur[index]] = False
    cur[index] = i
    res += 1

print(res)
