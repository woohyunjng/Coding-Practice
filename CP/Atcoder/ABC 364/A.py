from sys import stdin

input = stdin.readline

N = int(input())
arr = []

res = True

for i in range(N):
    arr.append(1 if input().rstrip() == "sweet" else 0)
    if i >= 1 and i < N - 1:
        if arr[i] and arr[i - 1]:
            res = False

print("Yes" if res else "No")
