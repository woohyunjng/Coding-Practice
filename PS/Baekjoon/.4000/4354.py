from sys import stdin
from math import ceil

while True:
    S = stdin.readline().rstrip()
    if S == ".":
        break

    pi = [0 for i in range(len(S))]
    j = 0

    for i in range(1, len(S)):
        while j > 0 and S[j] != S[i]:
            j = pi[j - 1]

        if S[i] == S[j]:
            j += 1
            pi[i] = j

    L = len(S) - pi[-1]
    if not len(S) % L:
        print(len(S) // L)
    else:
        print(1)
