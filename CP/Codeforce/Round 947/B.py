T = int(input())
for t in range(T):
    N = int(input())
    arr = list(map(int, input().split()))

    arr = list(sorted(arr))
    res = True

    A = arr[0]
    B = 0

    for i in range(1, N):
        if arr[i] % A:
            if not B:
                B = arr[i]
            else:
                if arr[i] % B:
                    res = False
    print("Yes" if res else "No")
