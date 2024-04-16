N = int(input())
print(*filter(lambda x: x % 3, range(1, N + 1)))
