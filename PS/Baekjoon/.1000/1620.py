N, M = map(int, input().split())
arr_num, arr_name = [0], {}

for i in range(1, N + 1):
    name = input()
    arr_num.append(name)
    arr_name[name] = i

for j in range(M):
    q = input()
    if q.isdigit():
        print(arr_num[int(q)])
    else:
        print(arr_name[q])
