N, M = map(int, input().split())
arr = [[0 for j in range(M)] for i in range(N)]
go = [[0, 1], [1, 0], [0, -1], [-1, 0]]

i, K = N * M, 0
Y, X = 0, -1
while i > 0:
    if (
        Y + go[K % 4][0] < N
        and Y + go[K % 4][0] >= 0
        and X + go[K % 4][1] < M
        and X + go[K % 4][1] >= 0
        and not arr[Y + go[K % 4][0]][X + go[K % 4][1]]
    ):
        Y += go[K % 4][0]
        X += go[K % 4][1]
        arr[Y][X] = i
        i -= 1
    else:
        K += 1

print("\n".join(map(lambda x: " ".join(map(str, x)), arr)))
