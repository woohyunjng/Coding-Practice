from collections import defaultdict

N = int(input())
check = defaultdict(bool)
arr = map(int, input().split())

for i in arr:
    check[i] = True

M = int(input())
arr = map(int, input().split())

for i in arr:
    print(1 if check[i] else 0, end=" ")
