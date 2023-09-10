N, M, K = map(int, input().split())
print(max(N - M * K, 0), max(N - M * (K - 1) - 1, 0))
