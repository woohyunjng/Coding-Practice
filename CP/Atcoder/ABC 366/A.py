from sys import stdin

input = stdin.readline

N, T, A = map(int, input().split())
if (N + 1) // 2 <= max(T, A):
    print("Yes")
else:
    print("No")
