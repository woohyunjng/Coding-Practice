from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N = int(input())
    arr = list(map(int, input().rstrip().split()))

    A = []
    res = sum(arr)

    cnt = [0 for i in range(N + 1)]
    mx = 0
    for i in arr:
        cnt[i] += 1
        if cnt[i] == 2:
            mx = max(mx, i)
        A.append(mx)

    res += sum(A)

    arr = A.copy()
    A = []
    cnt = [0 for i in range(N + 1)]
    mx = 0
    for i in arr:
        cnt[i] += 1
        if cnt[i] == 2:
            mx = max(mx, i)
        A.append(mx)

    cnt = [0 for i in range(N + 1)]
    B = []
    for i in A:
        cnt[i] += 1
        if cnt[i] == 1:
            B.append(i)

    cur = 0
    for j in range(len(B) - 1, -1, -1):
        K = B[j]
        res += K * cnt[K] * (cnt[K] + 1) // 2 + K * cnt[K] * cur
        cur += cnt[K]

    print(res)
