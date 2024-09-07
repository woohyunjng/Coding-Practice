from sys import stdin

input = stdin.readline

L, R = map(int, input().split())

if L == 1 and R == 1:
    print("Invalid")
elif L == 0 and R == 0:
    print("Invalid")
elif L == 1:
    print("Yes")
else:
    print("No")
