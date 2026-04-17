N, X = map(int, input().split())
arr = list(map(int, input().split()))

print(int(sum(arr) % X == 0))
