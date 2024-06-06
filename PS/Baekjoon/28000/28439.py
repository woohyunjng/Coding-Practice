from sys import stdin
from collections import defaultdict

N, M = map(int, stdin.readline().rstrip().split())
col_sum, row_sum = [0 for i in range(M)], [0 for i in range(N)]
arr = []

col_div, row_div = set([]), set([])
k_col_list, k_row_list = set([]), set([])

col_first_counter, row_first_counter = defaultdict(int), defaultdict(int)
col_sum_counter, row_sum_counter = defaultdict(int), defaultdict(int)

for i in range(N):
    line = list(map(int, stdin.readline().rstrip().split()))
    row_sum[i] = sum(line)
    row_div.add(row_sum[i] % M)
    k_row_list.add(row_sum[i])

    for j in range(M):
        col_sum[j] += line[j]

    arr.append(line)

    row_first_counter[line[0]] += 1
    row_sum_counter[row_sum[i]] += 1

for i in range(M):
    col_div.add(col_sum[i] % N)
    k_col_list.add(col_sum[i])

    col_first_counter[arr[0][i]] += 1
    col_sum_counter[col_sum[i]] += 1

if len(col_div) != 1 or len(row_div) != 1:
    print(-1)
    exit()

mn_Q_col, mn_Q_row, mn_arr_col, mn_arr_row = 1e9, 1e9, [], []
k_col_list, k_row_list = list(k_col_list), list(k_row_list)
mn_k_col, mn_k_row = 0, 0

for k in k_col_list:
    Q = N + M - col_sum_counter[k] - row_first_counter[(col_sum[0] - k) // N]

    if Q < mn_Q_col:
        mn_Q_col = Q
        mn_k_col = k

first_col = (col_sum[0] - mn_k_col) // N
for i in range(M):
    if not (col_sum[i] - mn_k_col):
        continue
    mn_arr_col.append(f"2 {i + 1} {(col_sum[i] - mn_k_col) // N}")

for i in range(N):
    if not (arr[i][0] - first_col):
        continue
    mn_arr_col.append(f"1 {i + 1} {arr[i][0] - first_col}")

for k in k_row_list:
    Q = N + M - row_sum_counter[k] - col_first_counter[(row_sum[0] - k) // M]

    if Q < mn_Q_row:
        mn_Q_row = Q
        mn_k_row = k

first_row = (row_sum[0] - mn_k_row) // M
for i in range(N):
    if not (row_sum[i] - mn_k_row):
        continue
    mn_arr_row.append(f"1 {i + 1} {(row_sum[i] - mn_k_row) // M}")

for i in range(M):
    if not (arr[0][i] - first_row):
        continue
    mn_arr_row.append(f"2 {i + 1} {arr[0][i] - first_row}")

if mn_Q_col <= mn_Q_row:
    print(mn_Q_col)
    for i in mn_arr_col:
        print(i)
else:
    print(mn_Q_row)
    for i in mn_arr_row:
        print(i)
