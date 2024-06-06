T = int(input())

for i in range(T):
    k = int(input())
    n = int(input())

    arr = [0] + [j for j in range(1, n + 1)]
    for j in range(k):
        for l in range(1, n + 1):
            arr[l] = arr[l - 1] + arr[l]

    print(arr[n])
