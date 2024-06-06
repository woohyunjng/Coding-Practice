N = int(input())
arr = []
compressed_arr = set([])

for i in range(N):
    x, y = map(int, input().split())
    arr.append((x, y))
    compressed_arr.add(x)
    compressed_arr.add(y)

compressed_arr = list(sorted(list(compressed_arr)))
get_c = {}

for i in range(len(compressed_arr)):
    get_c[compressed_arr[i]] = i

start = [0 for i in range(len(compressed_arr))]
end = [0 for i in range(len(compressed_arr))]

for i in range(N):
    start[get_c[arr[i][0]]] += 1
    end[get_c[arr[i][1]]] += 1

sm = [0 for i in range(len(compressed_arr))]
mx, bf = -1, False
st, ed = -1, -1

for i in range(len(compressed_arr)):
    if not i:
        sm[i] = start[i]
    else:
        sm[i] = sm[i - 1] + start[i] - end[i]

    if sm[i] > mx:
        mx = sm[i]
        st, ed = compressed_arr[i], -1
        bf = True
    elif sm[i] < mx:
        if bf:
            bf = False
            ed = compressed_arr[i]

print(mx)
print(st, ed if ed >= 0 else compressed_arr[-1])
