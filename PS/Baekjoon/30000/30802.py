from math import ceil

N = int(input())
S, M, L, XL, XXL, XXXL = map(int, input().split())
T, P = map(int, input().split())

T_res = (
    ceil(S / T)
    + ceil(M / T)
    + ceil(L / T)
    + ceil(XL / T)
    + ceil(XXL / T)
    + ceil(XXXL / T)
)
print(T_res)

print(N // P, N % P)
