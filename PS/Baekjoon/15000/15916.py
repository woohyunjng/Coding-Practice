N = int(input())
y = [0] + list(map(int, input().split()))
K = int(input())

res = 0
for i in range(N):
    if (y[i] - K * i) * (y[i + 1] - K * (i + 1)) <= 0:
        res += 1
    if K == y[1] - y[0]:
        res += 2
        break

if res >= 2:
    print("T")
else:
    print("F")
