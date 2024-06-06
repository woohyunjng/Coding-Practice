N = int(input())
arr = [[0 for j in range(N)] for i in range(N)]
go = [[0, 1], [1, 0], [0, -1], [-1, 0]]

i, K = 1, 0
Y, X = 0, -1
while i <= N**2:
    if (
        Y + go[K % 4][0] < N
        and Y + go[K % 4][0] >= 0
        and X + go[K % 4][1] < N
        and X + go[K % 4][1] >= 0
        and not arr[Y + go[K % 4][0]][X + go[K % 4][1]]
    ):
        Y += go[K % 4][0]
        X += go[K % 4][1]
        arr[Y][X] = i
        i += 1
    else:
        K += 1

print("\n".join(map(lambda x: " ".join(map(str, x)), arr)))
