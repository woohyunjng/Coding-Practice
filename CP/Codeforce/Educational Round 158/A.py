from sys import stdin
from string import ascii_lowercase

input = stdin.readline
T = int(input())

for t in range(T):
    S = input().rstrip()
    N = len(S)

    mx, res = 0, ""
    for i in range(N + 1):
        for s in ascii_lowercase:
            K = S[:i] + s + S[i:]
            val = 2
            for j in range(1, N + 1):
                if K[j] == K[j - 1]:
                    val += 1
                else:
                    val += 2
            if val > mx:
                mx = val
                res = K

    print(res)
