def multiply(arr1, arr2, size):
    res = []
    for i in range(size):
        res.append([])
        for j in range(size):
            x = 0
            for k in range(size):
                x += arr1[i][k] * arr2[k][j]
            res[i].append(x % 1000)

    return res


def pow(arr, N, B):
    if B == 1:
        return arr

    min_arr = pow(arr, N, B // 2)
    if B % 2:
        res = multiply(multiply(min_arr, min_arr, N), arr, N)
    else:
        res = multiply(min_arr, min_arr, N)

    return res


N, B = map(int, input().split())
arr = []

for i in range(N):
    arr.append(list(map(int, input().split())))

res = pow(arr, N, B)
for i in range(N):
    for j in range(N):
        print(res[i][j] % 1000, end=" ")
    print()
