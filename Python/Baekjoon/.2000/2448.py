from math import log2
from sys import stdin, stdout

N = int(log2(int(stdin.readline().rstrip()) // 3)) + 1
S = [[], ["  *  ", " * * ", "*****"]]
space = " " * 3

for i in range(2, N + 1):
    K = []

    for j in S[-1]:
        K.append("".join([space, j, space]))
    space = "".join([space, space])

    for j in S[-1]:
        K.append(" ".join([j, j]))
    
    S.append(K)

stdout.write("\n".join(S[-1]))
