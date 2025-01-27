N = int(input())
dp = [[0 for j in range(1 << N - 1)] for i in range(N)]
arr = []

for i in range(N):
    arr.append(tuple(map(int, input().split())))


def dis(a, b):
    return ((arr[a][0] - arr[b][0]) ** 2 + (arr[a][1] - arr[b][1]) ** 2) ** 0.5


def dfs(i, c):
    if dp[i][c]:
        return dp[i][c]
    if c == (1 << (N - 1)) - 1:
        return dis(i, 0)

    mn = 1e9
    for j in range(1, N):
        if c & (1 << j - 1):
            continue
        mn = min(mn, dis(i, j) + dfs(j, c | (1 << (j - 1))))

    dp[i][c] = mn
    return dp[i][c]


dfs(0, 0b0)
print(dp[0][0b0])
