checked = [True for i in range(10101)]

for i in range(1, 10001):
    checked[int(i + sum(map(int, str(i))))] = False

for i in range(1, 10001):
    if checked[i]:
        print(i)
