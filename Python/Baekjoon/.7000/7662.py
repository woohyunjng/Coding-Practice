from heapq import heappush, heappop
from sys import stdin

T = int(stdin.readline().rstrip())
for i in range(T):
    k = int(stdin.readline().rstrip())
    s = 0

    q_small = []
    q_big = []

    checked = [False for i in range(k)]

    for j in range(k):
        S = stdin.readline().rstrip()
        if S == "D 1":
            if s:
                s -= 1
                while True:
                    x = heappop(q_big)
                    if checked[x[1]]:
                        checked[x[1]] = False
                        break
        elif S == "D -1":
            if s:
                s -= 1
                while True:
                    x = heappop(q_small)
                    if checked[x[1]]:
                        checked[x[1]] = False
                        break
        else:
            n = int(S[2:])
            heappush(q_small, (n, j))
            heappush(q_big, (n * (-1), j))
            checked[j] = True
            s += 1

    if not s:
        print("EMPTY")
    else:
        while True:
            mx = heappop(q_big)
            if checked[mx[1]]:
                mx = mx[0] * (-1)
                break
        while True:
            mn = heappop(q_small)
            if checked[mn[1]]:
                mn = mn[0]
                break

        print(mx, mn)
