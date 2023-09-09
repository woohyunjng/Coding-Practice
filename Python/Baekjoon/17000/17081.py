from sys import stdin

N, M = map(int, stdin.readline().rstrip().split())
arr = []

monsters, items = 0, 0

for i in range(N):
    arr.append(list(stdin.readline().rstrip()))
    for j in range(M):
        if arr[i][j] == "@":
            pos = [i, j]
            arr[i][j] = "."
        elif arr[i][j] in ["&", "M"]:
            monsters += 1
        elif arr[i][j] == "B":
            items += 1

first_pos = pos.copy()

HP, att, df = 20, 2, 2
level, exp = 1, 0
maxHP = 20

weapon, armor = 0, 0
acc = {"HR": False, "RE": False, "CO": False, "EX": False, "DX": False, "HU": False, "CU": False}
used_acc = 0

go = list(stdin.readline().rstrip())
T = 0

monster = {}
for i in range(monsters):
    inp = list(stdin.readline().rstrip().split())
    monster[(int(inp[0]) - 1, int(inp[1]) - 1)] = [
        inp[2],  # 이름
        int(inp[3]),  # 공격력
        int(inp[4]),  # 방어력
        int(inp[5]),  # 최대 체력
        int(inp[6]),  # 얻을 수 있는 경험치
    ]

item = {}
for i in range(items):
    inp = list(stdin.readline().rstrip().split())
    if inp[2] == "W":
        item[(int(inp[0]) - 1, int(inp[1]) - 1)] = [0, int(inp[3])]  # 공격력
    elif inp[2] == "A":
        item[(int(inp[0]) - 1, int(inp[1]) - 1)] = [1, int(inp[3])]  # 방어력
    else:
        item[(int(inp[0]) - 1, int(inp[1]) - 1)] = [2, inp[3]]  # 장신구

res = ""
boss_clear = False

for i in go:
    T += 1

    if i == "U" and pos[0] and arr[pos[0] - 1][pos[1]] != "#":
        pos[0] -= 1
    elif i == "D" and pos[0] != N - 1 and arr[pos[0] + 1][pos[1]] != "#":
        pos[0] += 1
    elif i == "L" and pos[1] and arr[pos[0]][pos[1] - 1] != "#":
        pos[1] -= 1
    elif i == "R" and pos[1] != M - 1 and arr[pos[0]][pos[1] + 1] != "#":
        pos[1] += 1

    A = arr[pos[0]][pos[1]]

    if A == ".":
        continue

    elif A == "^":
        if acc["DX"]:
            HP -= 1
        else:
            HP -= 5

        if HP <= 0:
            if acc["RE"]:
                pos = first_pos.copy()
                HP = maxHP
                acc["RE"] = False
                used_acc -= 1
            else:
                res = "YOU HAVE BEEN KILLED BY SPIKE TRAP.."
                break

    elif A == "B":
        it = item[*pos]
        if it[0] == 0:
            weapon = it[1]
        elif it[0] == 1:
            armor = it[1]
        else:
            if used_acc < 4 and not acc[it[1]]:
                used_acc += 1
                acc[it[1]] = True

        arr[pos[0]][pos[1]] = "."

    elif A == "&":
        mn = monster[*pos].copy()
        j = 0

        while True:
            j += 1

            if j % 2:
                if j == 1:
                    if acc["DX"] and acc["CO"]:
                        mn[3] -= max(1, (att + weapon) * 3 - mn[2])
                    elif acc["CO"]:
                        mn[3] -= max(1, (att + weapon) * 2 - mn[2])
                    else:
                        mn[3] -= max(1, att + weapon - mn[2])
                else:
                    mn[3] -= max(1, att + weapon - mn[2])

                if mn[3] <= 0:
                    arr[pos[0]][pos[1]] = "."
                    if acc["HR"]:
                        HP = min(HP + 3, maxHP)
                    if acc["EX"]:
                        exp += int(mn[4] * 1.2)
                    else:
                        exp += mn[4]
                    break
            else:
                HP -= max(1, mn[1] - armor - df)
                if HP <= 0:
                    if not acc["RE"]:
                        res = f"YOU HAVE BEEN KILLED BY {mn[0]}.."
                        break
                    else:
                        pos = first_pos.copy()
                        HP = maxHP
                        acc["RE"] = False
                        used_acc -= 1
                        break

    elif A == "M":
        boss_clear = False
        mn = monster[*pos].copy()
        j = 0

        if acc["HU"]:
            HP = maxHP

        while True:
            j += 1

            if j % 2:
                if j == 1:
                    if acc["DX"] and acc["CO"]:
                        mn[3] -= max(1, (att + weapon) * 3 - mn[2])
                    elif acc["CO"]:
                        mn[3] -= max(1, (att + weapon) * 2 - mn[2])
                    else:
                        mn[3] -= max(1, att + weapon - mn[2])
                else:
                    mn[3] -= max(1, att + weapon - mn[2])

                if mn[3] <= 0:
                    arr[pos[0]][pos[1]] = "."
                    if acc["HR"]:
                        HP = min(HP + 3, maxHP)
                    if acc["EX"]:
                        exp += int(mn[4] * 1.2)
                    else:
                        exp += mn[4]

                    boss_clear = True
                    break
            else:
                if j == 2 and acc["HU"]:
                    continue

                HP -= max(1, mn[1] - armor - df)
                if HP <= 0:
                    if not acc["RE"]:
                        res = f"YOU HAVE BEEN KILLED BY {mn[0]}.."
                    else:
                        pos = first_pos.copy()
                        HP = maxHP
                        acc["RE"] = False
                        used_acc -= 1
                    break

    if exp >= level * 5:
        level += 1
        exp = 0

        att += 2
        df += 2
        maxHP += 5
        HP = maxHP

    if HP <= 0:
        break

    if boss_clear:
        res = "YOU WIN!"
        break

if HP > 0:
    arr[pos[0]][pos[1]] = "@"

for i in arr:
    print("".join(i))

print(f"Passed Turns : {T}")
print(f"LV : {level}")
print(f"HP : {max(HP, 0)}/{maxHP}")
print(f"ATT : {att}+{weapon}")
print(f"DEF : {df}+{armor}")
print(f"EXP : {exp}/{5 * level}")

if res == "":
    res = "Press any key to continue."

print(res)
