from sys import stdin

input = stdin.readline

T = int(input())

for t in range(T):
    N = int(input())
    S = input().rstrip()

    S = S.lstrip("0")
    cut = N - len(S)
    N = len(S)

    if not N:
        print("0")
        continue

    if S.count("1") == N:
        if cut > 0:
            print(S)
        else:
            print("1" * (N - 1) + "0")
        continue

    K = 0
    for i in range(N):
        if S[i] == "0":
            break
        K += 1

    A = K
    j = K
    while j < N and K > 0:
        if S[j] == "0":
            K -= 1
        else:
            break
        j += 1

    A = S[K : K + N - A]
    print(bin(int(f"0b{A}", 2) ^ int(f"0b{S}", 2))[2:])
