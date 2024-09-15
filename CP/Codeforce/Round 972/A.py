from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N = int(input())
    res = []

    for i in range(N):
        res.append(["a", "e", "i", "o", "u"][i % 5])

    res = sorted(res)

    print("".join(res))
