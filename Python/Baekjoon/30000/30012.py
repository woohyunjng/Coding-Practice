from sys import stdin

S, N = map(int, stdin.readline().rstrip().split())
E = list(map(lambda x: abs(int(x) - S), stdin.readline().rstrip().split()))
K, L = map(int, stdin.readline().rstrip().split())

mn, mn_index = 1e9, 0

for i in range(N):
    if E[i] > 2 * K:
        res = (E[i] - 2 * K) * L
    else:
        res = K * 2 - E[i]
    if res < mn:
        mn = res
        mn_index = i + 1

print(mn, mn_index)
