sm_m, sm = 0, 0
dc = {
    "A+": 4.5,
    "A0": 4.0,
    "B+": 3.5,
    "B0": 3.0,
    "C+": 2.5,
    "C0": 2.0,
    "D+": 1.5,
    "D0": 1.0,
    "F": 0.0,
}

for i in range(20):
    a, b, c = input().split()
    if c == "P":
        continue

    sm_m += float(b) * dc[c]
    sm += float(b)

print(sm_m / sm)
