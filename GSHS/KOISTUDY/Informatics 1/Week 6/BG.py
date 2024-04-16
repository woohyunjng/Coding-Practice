N = int(input())
arr = list(map(int, input().split()))
for i in range(1, 24):
    print(arr.count(i), end=" ")
