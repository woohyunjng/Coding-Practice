N, K, X = map(int, input().split())
arr = list(map(int, input().split()))

arr.insert(K, X)
print(*arr)
