from sys import stdin

input = stdin.readline

T = int(input())

for t in range(T):
    N = int(input())
    print("YES")
    for i in range(N):
        print(i + 1, end=" ")
    print()
