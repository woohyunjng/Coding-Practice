H, W = map(int, input().split())
arr = [[0 for j in range(W)] for i in range(H)]

N = int(input())
for i in range(N):
    L, D, Y, X = map(int, input().split())
    if not D:
        for j in range(L):
            arr[Y - 1][X - 1 + j] = 1
    else:
        for j in range(L):
            arr[Y - 1 + j][X - 1] = 1

print("\n".join(map(lambda x: " ".join(map(str, x)), arr)))
