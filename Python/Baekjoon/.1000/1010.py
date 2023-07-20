from math import comb

T = int(input())
for i in range(T):
    N, M = map(int, input().split())
    print(comb(M, N))
