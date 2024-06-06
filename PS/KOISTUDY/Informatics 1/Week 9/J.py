from bisect import bisect_right

N = int(input())
arr = list(map(int, input().split()))
K = int(input())
print(bisect_right(arr, K) + 1)
