N, k = map(int, input().split())
arr = list(sorted(map(int, input().split()), reverse=True))

print(arr[k - 1])
