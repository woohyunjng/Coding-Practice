from sys import stdin

N, H = map(int, stdin.readline().rstrip().split())
arr = list([{"S": 0, "R": 1, "W": 2}[i] for i in input()])

if N == 1:
    print(0)
elif N == 2:
    if H == 1 or arr[0] != arr[1]:
        print(0)
    else:
        print(1)
elif N == 3:
    if len(set(arr)) == 3 or H == 1:
        print(0)
    elif H == 2:
        if arr[0] == arr[1] and arr[0] == arr[2]:
            print(1)
        elif arr[0] == arr[2]:
            print(0)
        elif arr[0] == arr[1] or arr[1] == arr[2]:
            print(1)
    else:
        if len(set(arr)) == 2:
            print(1)
        else:
            print(2)
else:
    if H == 1:
        print(0)
    elif H == 2:
        res = 0
        before = False

        for i in range(N - 1):
            if arr[i] == arr[i + 1] and not before:
                before = True
                res += 1
            else:
                before = False
        print(res)
    elif H == 3:
        barr = [
            list([i % 3 for i in range(N)]),
            list([i % 3 for i in range(1, N + 1)]),
            list([i % 3 for i in range(2, N + 2)]),
            list([2 - i % 3 for i in range(N)]),
            list([2 - i % 3 for i in range(1, N + 1)]),
            list([2 - i % 3 for i in range(2, N + 2)]),
        ]
        res = [0, 0, 0, 0, 0, 0]

        for i in range(N):
            for j in range(6):
                if arr[i] != barr[j][i]:
                    res[j] += 1
        print(min(res))
    else:
        print(-1)
