from sys import stdin

input = stdin.readline

H, W = map(int, input().split())
S_i, S_j = map(int, input().split())
S_i -= 1
S_j -= 1

arr = []
for i in range(H):
    arr.append(list(input().rstrip()))

X = input().rstrip()

for i in X:
    if i == "L":
        if S_j - 1 >= 0 and arr[S_i][S_j - 1] == ".":
            S_j -= 1
    elif i == "R":
        if S_j + 1 < W and arr[S_i][S_j + 1] == ".":
            S_j += 1
    elif i == "U":
        if S_i - 1 >= 0 and arr[S_i - 1][S_j] == ".":
            S_i -= 1
    elif i == "D":
        if S_i + 1 < H and arr[S_i + 1][S_j] == ".":
            S_i += 1

print(S_i + 1, S_j + 1)
