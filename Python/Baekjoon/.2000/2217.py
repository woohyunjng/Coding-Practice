N = int(input())
arr, mx = [], -1

for i in range(N):
    arr.append(int(input()))

arr = list(sorted(arr))
for i in range(N):
    mx = max(mx, arr[i] * (N - i))

print(mx)
