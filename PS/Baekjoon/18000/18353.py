from bisect import bisect_left

N = int(input())
arr = list(map(int, input().split()))
lis = []

for i in reversed(arr):
    if not lis or lis[-1] < i:
        lis.append(i)
    else:
        lis[bisect_left(lis, i)] = i

print(N - len(lis))
