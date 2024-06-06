from sys import stdin

N = int(stdin.readline())
arr = [0 for i in range(10001)]

for i in range(N):
    arr[int(stdin.readline())] += 1

for i in range(1, 10001):
    if arr[i]:
        for j in range(arr[i]):
            print(i)
