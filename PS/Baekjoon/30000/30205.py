N, M, P = map(int, input().split())
finish = True

for i in range(N):
    arr = list(sorted(map(int, input().split())))
    item = 0

    for j in arr:
        if j == -1:
            item += 1
            continue
        elif P < j:
            while P < j and item:
                P *= 2
                item -= 1

        if P < j:
            finish = False
        else:
            finish = finish and True
            P += j

    while item:
        P *= 2
        item -= 1

print(int(finish))
