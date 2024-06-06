N = int(input())
S = input()

lever = 0
time = 0
train = 0

res = 0

for i in S:
    if i == "P":
        lever += 1
    if i == "W":
        time += 1

        if time == 1:
            train = lever
        elif time == 2:
            if lever != train:
                res = 6
            elif not train % 2:
                res = 5
            else:
                res = 1
            break

print(res)
