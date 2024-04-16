N = int(input())
arr = list(map(int, input().split()))

last = 0
for i in arr:
    last += i
    print(last, end=" ")
