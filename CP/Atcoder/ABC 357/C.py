from math import log
from sys import stdin, stdout

N = int(stdin.readline())

if not N:
    print("#")
    exit()

S = [[], ["###", "#.#", "###"]]

for i in range(2, N + 1):
    K = []

    for j in S[-1]:
        K.append("".join([j, j, j]))

    space = "".join(["." for j in range(3 ** (i - 1))])

    for j in S[-1]:
        K.append("".join([j, space, j]))

    for j in S[-1]:
        K.append("".join([j, j, j]))

    S.append(K)

stdout.write("\n".join(S[-1]))
