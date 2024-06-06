N, M = map(int, input().split())
print((M**N - (M - 1) ** N) % (10**9 + 7))
