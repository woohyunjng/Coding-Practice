from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N = int(input())
    arr = list(map(int, input().split()))
    print(*(arr[1:] + [arr[0]]))
