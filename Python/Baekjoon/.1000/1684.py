from math import gcd

n = int(input())
arr, arr_s = [], []

arr = list(map(int, input().split()))
for i in range(n - 1):
    arr_s.append(arr[i + 1] - arr[i])

print(gcd(*arr_s))
