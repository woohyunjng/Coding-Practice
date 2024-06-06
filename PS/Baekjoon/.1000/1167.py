from collections import deque

V = int(input())
arr = [[] for i in range(V + 1)]

for i in range(V):
    a = list(map(int, input().split()))
    j = 1
    while True:
        if a[j] == -1:
            break

        arr[a[0]].append([a[j], a[j + 1]])
        j += 2

dp = [[1, 0] for i in range(V + 1)]
checked = [False for i in range(V + 1)]
checked[1] = True
q = deque([1])

while len(q):
    p = q.popleft()
    for i in arr[p]:
        if checked[i[0]]:
            continue
        checked[i[0]] = True
        dp[i[0]] = [i[0], dp[p][1] + i[1]]
        q.append(i[0])

A = max(dp, key=lambda x: x[1])[0]

dp = [0 for i in range(V + 1)]
checked = [False for i in range(V + 1)]
checked[A] = True
q = deque([A])
while len(q):
    p = q.pop()
    for i in arr[p]:
        if checked[i[0]]:
            continue
        checked[i[0]] = True
        dp[i[0]] = dp[p] + i[1]
        q.append(i[0])

print(max(dp))
