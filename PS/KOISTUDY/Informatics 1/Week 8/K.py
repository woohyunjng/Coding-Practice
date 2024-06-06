N = int(input())
arr = [[N * i + N - j for j in range(N)] for i in range(N)]
print("\n".join(map(lambda x: " ".join(map(str, x)), arr)))
