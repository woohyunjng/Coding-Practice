from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N = int(input())
    if N == 1 or N == 3:
        print(-1)
        continue

    res = ""

    X = (N + 1) // 2 - N // 2 + 1
    if X == 1:
        res = "66" + "3" * (N - 2)
    else:
        res = "6636" + "3" * (N - 4)

    print("".join(reversed(res)))
