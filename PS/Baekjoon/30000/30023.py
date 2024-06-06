from sys import stdin

N = int(stdin.readline())
arr = [{"R": 0, "G": 1, "B": 2}[i] for i in input()]

val = 0
first, copy_arr = arr[0], arr.copy()
for i in range(1, N - 2):
    val += (first - copy_arr[i]) % 3
    copy_arr[i + 1] = (copy_arr[i + 1] - copy_arr[i] + first) % 3
    copy_arr[i + 2] = (copy_arr[i + 2] - copy_arr[i] + first) % 3
    copy_arr[i] = first
if copy_arr[N - 1] % 3 == copy_arr[N - 2] % 3 == first % 3:
    res = val
else:
    res = 1e9

val = 1
first, copy_arr = (arr[0] + 1) % 3, arr.copy()
copy_arr[0], copy_arr[1], copy_arr[2] = (
    (copy_arr[0] + 1) % 3,
    (copy_arr[1] + 1) % 3,
    (copy_arr[2] + 1) % 3,
)
for i in range(1, N - 2):
    val += (first - copy_arr[i]) % 3
    copy_arr[i + 1] = (copy_arr[i + 1] - copy_arr[i] + first) % 3
    copy_arr[i + 2] = (copy_arr[i + 2] - copy_arr[i] + first) % 3
    copy_arr[i] = first
if copy_arr[N - 1] % 3 == copy_arr[N - 2] % 3 == first % 3:
    res = min(res, val)

val = 2
first, copy_arr = (arr[0] + 2) % 3, arr.copy()
copy_arr[0], copy_arr[1], copy_arr[2] = (
    (copy_arr[0] + 2) % 3,
    (copy_arr[1] + 2) % 3,
    (copy_arr[2] + 2) % 3,
)
for i in range(1, N - 2):
    val += (first - copy_arr[i]) % 3
    copy_arr[i + 1] = (copy_arr[i + 1] - copy_arr[i] + first) % 3
    copy_arr[i + 2] = (copy_arr[i + 2] - copy_arr[i] + first) % 3
    copy_arr[i] = first
if copy_arr[N - 1] % 3 == copy_arr[N - 2] % 3 == first % 3:
    res = min(res, val)

print(res if res < 1e9 else -1)
