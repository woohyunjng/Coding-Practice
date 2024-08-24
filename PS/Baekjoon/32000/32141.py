N, H = map(int, input().split())
arr = list(map(int, input().split()))

cur, res = 0, 0
check = False

for i in arr:
    cur += i
    res += 1
    if cur >= H:
        check = True
        break

if not check:
    res = -1

print(res)
