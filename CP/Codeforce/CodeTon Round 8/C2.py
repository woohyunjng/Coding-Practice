# 464 / 750

from collections import deque

T = int(input())
for i in range(T):
    N, X, Y = map(int, input().split())
    arr = list(sorted(map(int, input().split())))

    res = X - 2
    ev, od = 0, []

    for j in range(1, X):
        if 2 == arr[j] - arr[j - 1]:
            res += 1
        else:
            if (arr[j] - arr[j - 1]) % 2:
                ev += arr[j] - arr[j - 1] - 1
            else:
                od.append(arr[j] - arr[j - 1] + 1)

    if arr[-1] - arr[0] == N - 2:
        res += 1
    elif (N - (arr[-1] - arr[0])) % 2:
        ev += N - (arr[-1] - arr[0]) - 1
    else:
        od.append(N - (arr[-1] - arr[0]) + 1)

    od = deque(sorted(od))
    while Y and od:
        j = od.popleft()
        if (j - 5) // 2 + 1 > Y:
            res += Y * 2
            Y = 0
        else:
            res += (j - 5) // 2 * 2 + 3
            Y -= (j - 5) // 2 + 1

    print(res + min(Y * 2, ev))
