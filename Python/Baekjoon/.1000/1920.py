N = int(input())
A = map(int, input().split())
A = list(sorted(A))

M = int(input())
B = list(map(int, input().split()))

for i in B:
    st, en, f = 0, N - 1, False
    while st <= en:
        md = (st + en) // 2
        if A[md] == i:
            f = True
            break
        elif A[md] > i:
            en = md - 1
        else:
            st = md + 1

    if f:
        print(1, end=" ")
    else:
        print(0, end=" ")
