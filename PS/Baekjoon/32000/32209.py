Q = int(input())
res = True
cur = 0

for q in range(Q):
    A, B = map(int, input().split())
    if A == 1:
        cur += B
    else:
        cur -= B
        res = res and (cur >= 0)

print("See you next month" if res else "Adios")
