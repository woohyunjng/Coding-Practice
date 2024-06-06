arr = []
for i in range(10):
    arr.append(input().split())

res = False

for i in range(10):
    res = res or all([arr[j][i] == arr[0][i] for j in range(10)])
    res = res or all([arr[i][j] == arr[i][0] for j in range(10)])

print(int(res))
