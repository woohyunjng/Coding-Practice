N = int(input())
res = 0
arr = list(map(int, input().split()))

for i in range(N - 1):
    res += arr[i] * 180

res += (arr[N - 1] - 2) * 180
print(res)
