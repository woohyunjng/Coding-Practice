from sys import stdin

input = stdin.readline

N = int(input())
arr = []

for i in range(N):
    arr.append(list(map(int, input().split())))

res = 1

for i in range(1, N + 1):
    if res >= i:
        res = arr[res - 1][i - 1]
    else:
        res = arr[i - 1][res - 1]

print(res)
