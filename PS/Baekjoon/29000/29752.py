N = int(input())
dp = [0]

streak = False
arr = list(map(int, input().split()))

for i in arr:
    if not i:
        streak = False
        dp.append(0)
    else:
        if streak:
            dp.append(dp[-1] + 1)
        else:
            dp.append(1)
            streak = True

print(max(dp))
