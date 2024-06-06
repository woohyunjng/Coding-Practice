from bisect import bisect_right

L = int(input())
arr = list(map(int, input().split()))
arr = list(sorted(arr))

N = int(input())

i = bisect_right(arr, N)
if i:
    print(max((N - arr[i - 1]) * (arr[i] - N) - 1, 0))
else:
    print(N * (arr[0] - N) - 1)
