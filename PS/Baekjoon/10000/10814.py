N = int(input())
arr = []

for i in range(N):
    a, b = input().split()
    arr.append([int(a), b, int(a) * 1000000 + N])

arr = sorted(arr, key=lambda x: x[2])

for a, b, c in arr:
    print(a, b)
