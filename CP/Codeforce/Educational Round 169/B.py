from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    l, r = map(int, input().split())
    L, R = map(int, input().split())

    if L < l:
        l, r, L, R = L, R, l, r
    if l == L:
        r, R = max(r, R), min(r, R)

    if r < L:
        print(1)
    elif r == L:
        print(2)
    else:
        if l == L and r == R:
            print(R - L)
        elif l == L or r == R:
            print(R - L + 1)
        elif R < r:
            print(R - L + 2)
        else:
            print(r - L + 2)
