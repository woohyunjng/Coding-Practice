N, M = map(int, input().split())
cnt = [0 for i in range(N)]

for i in range(M):
    A, B = input().split()
    A = int(A)
    res = False

    if B == "M":
        cnt[A - 1] += 1
        res = cnt[A - 1] == 1

    print("Yes" if res else "No")
