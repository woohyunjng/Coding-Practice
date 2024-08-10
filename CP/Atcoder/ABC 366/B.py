from sys import stdin

input = stdin.readline

N = int(input())
M = 0

arr = []

for i in range(N):
    S = input().rstrip()
    arr.append(S)
    M = max(M, len(S))

for i in range(M):
    val = ""
    empt = 0
    for j in range(N - 1, -1, -1):
        if i < len(arr[j]):
            val += "*" * empt + arr[j][i]
            empt = 0
        else:
            empt += 1
    print(val)
