from collections import defaultdict

T = int(input())
for i in range(T):
    cloth = defaultdict(int)
    n = int(input())
    res = 1

    for j in range(n):
        a, b = input().split()
        cloth[b] += 1

    for i in cloth.values():
        res *= i + 1
    
    print(res - 1)
