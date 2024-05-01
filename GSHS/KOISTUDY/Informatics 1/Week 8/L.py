N = int(input())
arr = [
    [N * i + N - j if not i % 2 else N * i + j + 1 for j in range(N)] for i in range(N)
]
print("\n".join(map(lambda x: " ".join(map(str, x)), arr)))
