X = int(input())
N = int(input())
res = 0

for i in range(N):
    a, b = map(int, input().split())
    res += a * b

print("Yes" if X == res else "No")
