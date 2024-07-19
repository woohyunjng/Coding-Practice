from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N = int(input())
    arr = list(map(int, input().rstrip().split()))
    ang = [[] for i in range(N + 1)]

    P, Q = [0 for i in range(N)], [0 for i in range(N)]
    cur = 0

    for i in range(N):
        ang[arr[i]].append(i)

    P_cur, Q_cur = [], []

    res = True
    for i in range(N, 0, -1):
        if len(ang[i]) > 2:
            res = False
            break
        elif len(ang[i]) == 2:
            A, B = ang[i]
            P[A] = Q[B] = i
            P_cur.append(B)
            Q_cur.append(A)
        elif len(ang[i]) == 1:
            A = ang[i][0]
            P[A] = i
            Q[A] = i
        elif len(ang[i]) == 0:
            if len(P_cur) == 0 or len(Q_cur) == 0:
                res = False
                break
            P[P_cur.pop()] = i
            Q[Q_cur.pop()] = i

    if not res:
        print("NO")
        continue

    print("YES")
    print(*P)
    print(*Q)
