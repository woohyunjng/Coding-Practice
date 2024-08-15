from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N = int(input())
    arr = list(map(int, input().split()))

    if N >= 4:
        print("NO")
    if N == 3:
        print("YES" if arr[1] * 2 == arr[0] + arr[2] else "NO")
    if N == 2:
        print("YES" if arr[0] + 1 < arr[1] else "NO")
