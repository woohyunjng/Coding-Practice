N, M, Q = map(int, input().split())
col, row = [0 for i in range(N + 1)], [0 for i in range(M + 1)]

for i in range(Q):
    a, b, c = map(int, input().split())
    if a == 1:
        col[b] += c
    else:
        row[b] += c

for i in range(1, N + 1):
    for j in range(1, M + 1):
        print(col[i] + row[j], end=" ")
    print()
