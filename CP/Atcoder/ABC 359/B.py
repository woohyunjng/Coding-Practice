N = int(input())
arr = list(map(int, input().split()))

res = 0
for i in range(2 * N - 2):
    if arr[i] == arr[i + 2]:
        res += 1

print(res)
