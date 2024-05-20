from bisect import bisect_left

N = int(input())
arr = list(map(int, input().split()))
K = int(input())
print(bisect_left(arr, K) + 1)
