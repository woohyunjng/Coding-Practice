from math import lcm

T = int(input())
for i in range(T):
    A, B = map(int, input().split())
    print(lcm(A, B))
