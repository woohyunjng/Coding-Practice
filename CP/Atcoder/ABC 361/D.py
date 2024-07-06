from collections import deque, defaultdict

N = int(input())
S = list(map(lambda x: {"B": 1, "W": 2}[x], input())) + [0, 0]
T = list(map(lambda x: {"B": 1, "W": 2}[x], input())) + [0, 0]

if S.count(1) != T.count(1):
    print(-1)
    exit()

res = -1
q = deque([])
q.append((S, N, 0))
checked = defaultdict(bool)
checked["".join(map(str, S))] = True

while q:
    A, X, cnt = q.popleft()
    if A == T:
        res = cnt
        break

    for i in range(N + 1):
        if i == X or i == X + 1 or i == X - 1:
            continue
        K = A.copy()
        K[X], K[X + 1] = K[i], K[i + 1]
        K[i], K[i + 1] = 0, 0
        if checked["".join(map(str, K))]:
            continue
        checked["".join(map(str, K))] = True
        q.append((K, i, cnt + 1))

print(res)
