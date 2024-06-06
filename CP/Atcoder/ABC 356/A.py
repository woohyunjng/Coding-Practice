N, L, R = map(int, input().split())
arr = list(range(1, N + 1))
arr[L - 1 : R] = arr[L - 1 : R][::-1]
print(*arr)
