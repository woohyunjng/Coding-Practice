from sys import stdin

input = stdin.readline
INF = 0x7F7F7F7F7F7F7F7F


class Line:
    def __init__(self, A, B):
        self.A, self.B = A, B

    def get(self, X):
        return self.A * X + self.B


class Node:
    def __init__(self, s, e, line: Line):
        self.s, self.e = s, e
        self.line = line
        self.l, self.r = -1, -1


class LiChaoTree:
    tree = []

    def __init__(self, s, e):
        self.clear(s, e)

    def clear(self, s, e):
        self.tree = [Node(s, e, Line(0, -INF))]

    def update(self, n, v: Line):
        s, e = self.tree[n].s, self.tree[n].e
        low, high = self.tree[n].line, v

        if low.get(s) > high.get(s):
            low, high = high, low
        if low.get(e) <= high.get(e):
            self.tree[n].line = high
            return

        if low.get(s + e >> 1) < high.get(s + e >> 1):
            self.tree[n].line = high
            if self.tree[n].r == -1:
                self.tree[n].r = len(self.tree)
                self.tree.append(Node((s + e >> 1) + 1, e, Line(0, -INF)))
            self.update(self.tree[n].r, low)
        else:
            self.tree[n].line = low
            if self.tree[n].l == -1:
                self.tree[n].l = len(self.tree)
                self.tree.append(Node(s, (s + e >> 1), Line(0, -INF)))
            self.update(self.tree[n].l, high)

    def query(self, n, x):
        if n == -1:
            return -INF
        s, e = self.tree[n].s, self.tree[n].e
        if x <= s + e >> 1:
            return max(self.tree[n].line.get(x), self.query(self.tree[n].l, x))
        return max(self.tree[n].line.get(x), self.query(self.tree[n].r, x))

    def upd(self, v: Line):
        self.update(0, v)

    def q(self, x):
        return self.query(0, x)


N, K = map(int, input().split())

A, sm = [0 for i in range(N + 1)], [0]
dp = [[0 for i in range(K + 1)] for j in range(N + 1)]

for i in range(1, N + 1):
    A[i] = int(input())
    sm.append(A[i] + sm[i - 1])

tree = LiChaoTree(-INF, INF)
for i in range(N + 1):
    dp[i][0] = 1

for i in range(1, K + 1):
    tree.clear(-INF, INF)
    tree.upd(Line(-dp[0][i - 1], 0))
    tree.upd(Line(dp[0][i - 1], 0))

    for j in range(1, N + 1):
        dp[j][i] = max(dp[j - 1][i], tree.q(sm[j]))
        tree.upd(Line(-dp[j][i - 1], sm[j] * dp[j][i - 1]))
        tree.upd(Line(dp[j][i - 1], -sm[j] * dp[j][i - 1]))

res = 0
for i in range(N + 1):
    for j in range(1, K + 1):
        res = max(res, dp[i][j])
print(res)
