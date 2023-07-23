K = int(input())
i = 1

while True:
    if K <= 2 ** (i + 1) - 2:
        break
    i += 1

K -= 2 ** i - 1
res = ""

for j in range(i - 1, -1, -1):
    if K >= 2 ** j:
        K -= 2 ** j
        res += "7"
    else:
        res += "4"

print(res)
