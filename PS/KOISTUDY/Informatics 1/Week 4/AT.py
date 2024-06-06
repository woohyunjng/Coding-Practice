N = int(input())
arr = list(map(int, input().split()))

for i in range(2, N):
    if arr[i] < arr[i - 1] + arr[i - 2]:
        print("No")
        break
else:
    print("Yes")
