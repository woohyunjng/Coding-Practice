from collections import deque

N, K = map(int, input().split())
q = deque([N])

checked = [[-1, 0] for i in range(100001)]
checked[N] = [0, 1]

while len(q):
    A = q.popleft()
    arr = [A + 1, A - 1, A * 2]

    for i in arr:
        if i < 0 or i >= 100001:
            continue

        if checked[i][0] == -1:
            checked[i] = [checked[A][0] + 1, checked[A][1]]
            q.append(i)
        elif checked[i][0] == checked[A][0] + 1:
            checked[i][1] += checked[A][1]

print(checked[K][0])
print(checked[K][1])
