N = int(input())
arr = []

for i in range(N):
    arr.append(int(input()))
arr = list(sorted(arr))

for i in range(N):
    print(arr[i])
