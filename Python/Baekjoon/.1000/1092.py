N = int(input())
crain = list(sorted(map(int, input().split()), reverse=True))

M = int(input())
box = list(sorted(map(int, input().split()), reverse=True))

if box[0] > crain[0]:
    print(-1)
    exit()

time = 0
while len(box):
    time += 1
    for i in crain:
        for j in box:
            if j > i:
                continue
            box.remove(j)
            break

print(time)
