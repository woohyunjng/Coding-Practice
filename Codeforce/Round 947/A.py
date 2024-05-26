T = int(input())
for t in range(T):
    N = int(input())
    arr = list(map(int, input().split()))
    arr = arr * 2
    res = False

    for i in range(N):
        ang = True
        for j in range(N - 1):
            ang = ang and (arr[i + j + 1] >= arr[i + j])
        res = res or ang

    if res:
        print("Yes")
    else:
        print("No")
