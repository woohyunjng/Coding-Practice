N, X = map(int, input().split())
A = list(map(int, input().split()))

print(" ".join(map(str, filter(lambda x: x < X, A))))
