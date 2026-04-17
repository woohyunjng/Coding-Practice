N = int(input())
arr = list(map(int, input().split()))
num, res = 1, 0

for i in arr:
    if i == num:
        num += 1
    else:
        res += 1

print(res)
