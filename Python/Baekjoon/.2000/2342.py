def get_power(a, b):
    if a == b:
        return 1
    elif 0 in [a, b]:
        return 2
    elif abs(a - b) == 2:
        return 4
    else:
        return 3


arr = list(map(int, input().split()))[:-1]
dp = [0 for i in range(25)]

before = [0]

for i in arr:
    new_dp = [1e9 for i in range(25)]
    new_before = set()

    for j in before:
        x, y = j // 5, j % 5
        new_dp[i * 5 + y] = min(new_dp[i * 5 + y], get_power(x, i) + dp[j])
        new_dp[x * 5 + i] = min(new_dp[x * 5 + i], get_power(y, i) + dp[j])
        new_before.add(i * 5 + y)
        new_before.add(x * 5 + i)

    dp, before = new_dp, list(new_before)

mn = 1e9
for i in before:
    mn = min(mn, dp[i])

print(mn)
