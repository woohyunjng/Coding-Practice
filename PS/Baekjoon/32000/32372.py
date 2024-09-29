N, M = map(int, input().split())

queries = []

for i in range(M):
    queries.append(list(map(int, input().split())))

for i in range(1, N + 1):
    for j in range(1, N + 1):
        check = True
        for k in queries:
            if k[2] == 1:
                check = check and (i < k[0] and j == k[1])
            elif k[2] == 2:
                check = check and (i < k[0] and j > k[1])
            elif k[2] == 3:
                check = check and (i == k[0] and j > k[1])
            elif k[2] == 4:
                check = check and (i > k[0] and j > k[1])
            elif k[2] == 5:
                check = check and (i > k[0] and j == k[1])
            elif k[2] == 6:
                check = check and (i > k[0] and j < k[1])
            elif k[2] == 7:
                check = check and (i == k[0] and j < k[1])
            elif k[2] == 8:
                check = check and (i < k[0] and j < k[1])

        if check:
            print(i, j)
            exit()
