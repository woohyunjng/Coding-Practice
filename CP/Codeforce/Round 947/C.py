T = int(input())
for t in range(T):
    N = int(input())
    arr = list(map(int, input().split()))
    mx = -1

    if N == 2:
        print(min(arr))
        continue

    for i in range(N - 2):
        sub_arr = list(sorted([arr[i], arr[i + 1], arr[i + 2]]))
        x = sub_arr[1]
        mx = max(mx, x)
    print(mx)
