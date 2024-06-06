N = int(input())
x = list(map(int, input().split()))
arr = [-1 for i in range(1000001)]
res = [0 for i in range(N)]

for i in range(N):
    arr[x[i]] = i

for i in range(N):
    for j in range(x[i] * 2, 1000001, x[i]):
        if arr[j] != -1:
            res[arr[j]] -= 1
            res[i] += 1

print(" ".join(map(str, res)))
