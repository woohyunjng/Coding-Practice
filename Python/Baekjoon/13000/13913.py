from collections import deque

N, K = map(int, input().split())
q = deque([N])

checked = [[-1, -1] for i in range(100001)]
checked[N] = [0, -1]

while len(q):
    A = q.popleft()
    arr = [A + 1, A - 1, A * 2]

    if A == K:
        break

    for i in arr:
        if i < 0 or i >= 100001 or checked[i][0] >= 0:
            continue
        checked[i] = [checked[A][0] + 1, A]
        q.append(i)

print(checked[K][0])
res = deque([K])
before = K

while checked[before][1] != -1:
    before = checked[before][1]
    res.appendleft(before)

print(" ".join(map(str, res)))
