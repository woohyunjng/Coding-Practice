from sys import stdin


def gcd(A, B):
    return gcd(B % A, A) if A else B


T = int(stdin.readline())
for t in range(T):
    N = int(stdin.readline())
    arr = list(map(int, stdin.readline().rstrip().split()))
    gcd_arr = []

    for i in range(N - 1):
        gcd_arr.append(gcd(arr[i], arr[i + 1]))

    sad = []
    res = True

    for i in range(N - 2):
        if gcd_arr[i] > gcd_arr[i + 1]:
            sad.append(i)

    if gcd_arr[N - 2] < gcd_arr[N - 3]:
        sad.append(N - 2)
    elif gcd_arr[N - 3] < gcd_arr[N - 4]:
        sad.append(N - 3)

    sad = list(sorted(sad))
    if len(sad):
        sad.append(sad[-1] + 1)
        sad.append(sad[-1] + 1)
        sad.append(sad[0] - 1)
        sad.append(sad[0] - 2)
        sad = list(set(sad))
    if res and len(sad):
        res = False
        for i in sad:
            if i < 0 or i > N - 1:
                continue
            if i == 0:
                test = gcd_arr[1:]
            elif i == N - 1:
                test = gcd_arr[:-1]
            else:
                test = (
                    gcd_arr[: i - 1] + [gcd(arr[i - 1], arr[i + 1])] + gcd_arr[i + 1 :]
                )
            if all([test[i] <= test[i + 1] for i in range(N - 3)]):
                res = True
                break

    print("YES" if res else "NO")
