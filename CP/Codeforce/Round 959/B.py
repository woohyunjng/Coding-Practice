from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N = int(input())
    S = input().rstrip()
    T = input().rstrip()

    S_first, T_first = 10000000000, 100000000000
    for i in range(N):
        if S[i] == "1":
            S_first = i
            break
    for i in range(N):
        if T[i] == "1":
            T_first = i
            break

    if S_first <= T_first:
        print("YES")
    else:
        print("NO")
