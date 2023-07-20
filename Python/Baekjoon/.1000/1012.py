T = int(input())

for i in range(T):
    M, N, K = map(int, input().split())
    arr, w_arr = [[False for j in range(N)] for i in range(M)], []
    checked = [[False for j in range(N)] for i in range(M)]
    worm = 0

    for j in range(K):
        X, Y = map(int, input().split())
        arr[X][Y] = True
        w_arr.append([X, Y])

    def dfs(X, Y):
        if not arr[X][Y]:
            return

        checked[X][Y] = True

        c = [(X + 1, Y), (X - 1, Y), (X, Y + 1), (X, Y - 1)]
        if X == M - 1:
            c.remove((X + 1, Y))
        elif X == 0:
            c.remove((X - 1, Y))

        if Y == N - 1:
            c.remove((X, Y + 1))
        elif Y == 0:
            c.remove((X, Y - 1))

        for X_, Y_ in c:
            if not checked[X_][Y_]:
                dfs(X_, Y_)

    for X, Y in w_arr:
        if not checked[X][Y]:
            dfs(X, Y)
            worm += 1

    print(worm)
