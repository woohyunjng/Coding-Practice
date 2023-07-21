N = int(input())
arr = []

for i in range(N):
    arr.append(list(map(int, input().split())))


def get(x, y, N, A):
    check1, check2 = True, True

    for i in range(x, x + N):
        for j in range(y, y + N):
            if not A[i][j]:
                check1 = False
            if A[i][j]:
                check2 = False
        if not check1 and not check2:
            break
    
    if check1:
        return [0, 1]
    elif check2:
        return [1, 0]

    res1, res2, res3, res4 = get(x, y, N // 2, A), get(x + N // 2, y, N // 2, A), get(x, y + N // 2, N // 2, A), get(x + N // 2, y + N // 2, N // 2, A)
    return [res1[0] + res2[0] + res3[0] + res4[0], res1[1] + res2[1] + res3[1] + res4[1]]


res = get(0, 0, N, arr)
print(res[0])
print(res[1])
