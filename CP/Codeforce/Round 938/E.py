# TLE

T = int(input())
for t in range(T):
    N = int(input())
    S = int("".join(["0b", input()]), 2)

    if S == (1 << N) - 1:
        print(N)
        continue

    res, num = 1, (1 << N) - 1
    for i in range(N, 1, -1):
        k = S
        for j in range(N - i + 1):
            if not k & 1:
                k ^= num
            k >>= 1
        if k == num >> 1:
            res = i
            break
        num >>= 1

    print(res)
