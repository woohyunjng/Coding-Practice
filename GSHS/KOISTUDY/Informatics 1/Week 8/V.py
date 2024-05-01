N = int(input())
res = 0

for i in range(N):
    res += int(input())

if res > 0:
    print(1)
elif res < 0:
    print(-1)
else:
    print(0)
