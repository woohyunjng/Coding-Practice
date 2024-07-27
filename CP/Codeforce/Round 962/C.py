from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N, Q = map(int, input().split())
    A = input().rstrip()
    B = input().rstrip()

    count_A = [[0 for j in range(26)] for i in range(N + 1)]
    count_B = [[0 for j in range(26)] for i in range(N + 1)]

    for i in range(1, N + 1):
        count_A[i] = count_A[i - 1][:]
        count_A[i][ord(A[i - 1]) - ord("a")] += 1

        count_B[i] = count_B[i - 1][:]
        count_B[i][ord(B[i - 1]) - ord("a")] += 1

    for q in range(Q):
        L, R = map(int, input().split())

        sub_A = [0 for i in range(26)]
        sub_B = [0 for i in range(26)]

        for i in range(26):
            sub_A[i] = count_A[R][i] - count_A[L - 1][i]
            sub_B[i] = count_B[R][i] - count_B[L - 1][i]

        res = 0
        for i in range(26):
            res += abs(sub_A[i] - sub_B[i])
        print(res // 2)
