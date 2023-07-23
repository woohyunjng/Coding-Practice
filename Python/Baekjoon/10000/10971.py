N, W = int(input()), []
mn = 1000000000000000000000000

for _ in range(N):
    W.append(list(map(int, input().split())))


def dfs(p, start, visited):
    visited[p] = True
    x, res = 0, mn

    for i in range(N):
        if W[p][i] and not visited[i]:
            res = min(res, dfs(i, start, visited) + W[p][i])
            visited[i] = False
        elif visited[i]:
            x += 1

    if x == N and W[p][start]:
        return W[p][start]

    return res


for i in range(N):
    mn = min(mn, dfs(i, i, [False for _ in range(N)]))

print(mn)
