N = int(input())
X = [0] + list(map(int, input().split()))
T = [0] + list(map(int, input().split()))
res = X[N]

for i in range(N, 0, -1):
    res = max(T[i], res)
    res += X[i] - X[i - 1]

print(res)
