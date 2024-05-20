H, W = map(int, input().split())
N = int(input())
arr = [[0 for j in range(W + 2)] for i in range(H + 2)]
prefix_sum = [[0 for j in range(W + 2)] for i in range(H + 2)]

for i in range(N):
    X1, Y1, X2, Y2 = list(map(int, input().split()))
    prefix_sum[X1][Y1] += 1
    prefix_sum[X1][Y2 + 1] -= 1
    prefix_sum[X2 + 1][Y1] -= 1
    prefix_sum[X2 + 1][Y2 + 1] += 1

for i in range(1, H + 1):
    for j in range(1, W + 1):
        arr[i][j] = (
            arr[i][j - 1] + arr[i - 1][j] + prefix_sum[i][j] - arr[i - 1][j - 1]
        ) % 2

print("\n".join(map(lambda x: " ".join(map(str, x[1 : W + 1])), arr[1 : H + 1])))
