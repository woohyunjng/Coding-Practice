arr = []
for i in range(5):
    arr.append(int(input()))

arr = list(sorted(arr))
print(sum(arr) // 5)
print(arr[2])
