from bisect import bisect_left

while True:
    try:
        N = int(input())
    except:
        break

    arr = list(map(int, input().split()))
    lis = []

    for i in arr:
        if not lis or lis[-1] < i:
            lis.append(i)
        else:
            lis[bisect_left(lis, i)] = i

    print(len(lis))
