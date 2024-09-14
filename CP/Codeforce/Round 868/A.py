from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N, K = map(int, input().split())
    B, C = N, N**2 - N - 2 * K
    if C & 1:
        print("NO")
        continue
    C //= 2

    D = B**2 - 4 * C
    if D < 0 or D**0.5 != int(D**0.5):
        print("NO")
        continue
    D = int(D**0.5)
    res = N + D
    if res & 1 or res <= 0:
        print("NO")
        continue
    res //= 2

    print("YES")
    for i in range(res):
        print(1, end=" ")
    for i in range(N - res):
        print(-1, end=" ")
    print()
