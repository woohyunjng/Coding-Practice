from bisect import bisect_left

N = int(input())
arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))

arr = []
sq = [0 for i in range(N + 1)]

for i in range(N):
    sq[arr1[i]] = i

for i in arr2:
    arr.append(sq[i])

lis, X = [], []
for i in arr:
    if not (lis) or lis[-1] < i:
        lis.append(i)
        X.append(len(lis) - 1)
    else:
        a = bisect_left(lis, i)
        lis[a] = i
        X.append(a)

j = len(lis) - 1
res = []

for i in range(N - 1, -1, -1):
    if X[i] == j:
        res.append(arr1[arr[i]])
        j -= 1

print(len(res))
print(" ".join(sorted(list(map(str, res)))))
