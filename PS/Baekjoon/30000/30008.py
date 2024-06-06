N, K = map(int, input().split())
G = list(map(int, input().split()))

for i in G:
    val = i * 100 // N

    if val <= 4:
        res = 1
    elif val <= 11:
        res = 2
    elif val <= 23:
        res = 3
    elif val <= 40:
        res = 4
    elif val <= 60:
        res = 5
    elif val <= 77:
        res = 6
    elif val <= 89:
        res = 7
    elif val <= 96:
        res = 8
    else:
        res = 9

    print(res, end=" ")
