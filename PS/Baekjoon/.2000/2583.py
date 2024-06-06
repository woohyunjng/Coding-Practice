from collections import deque

M, N, K = map(int, input().split())
arr = [[False for j in range(N)] for i in range(M)]
checked = [[False for j in range(N)] for i in range(M)]

for i in range(K):
    x1, y1, x2, y2 = map(int, input().split())
    for j in range(x1, x2):
        for k in range(y1, y2):
            arr[k][j] = True

ans = []
for i in range(M):
    for j in range(N):
        if arr[i][j] or checked[i][j]:
            continue
        checked[i][j] = True
        q = deque([(i, j)])

        res = 0

        while len(q):
            x, y = q.popleft()
            res += 1

            go = [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]

            for m, n in go:
                if m >= M or m < 0 or n >= N or n < 0 or arr[m][n] or checked[m][n]:
                    continue
                checked[m][n] = True
                q.append((m, n))

        ans.append(res)

ans = list(map(str, sorted(ans)))
print(len(ans))
print(" ".join(ans))
