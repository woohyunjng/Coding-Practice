N, M = map(int, input().split())
arr = [[0 for j in range(M)] for i in range(N)]
X, Y = 0, 0

for i in range(1, N * M + 1):
    if X < 0 or Y >= N:
        X = X + Y + 1
        Y = 0

    while X >= M:
        X -= 1
        Y += 1

    arr[Y][X] = i
    X -= 1
    Y += 1

print("\n".join(map(lambda x: " ".join(map(str, x)), arr)))
