alumnos = [
    ["Juan", 3.5],
    ["Lucia", 5.0],
    ["Karen", 4.5],
    ["Samuel", 1.0]
]

m = len(alumnos)

for i in range(m):
    for j in range(0, m - i - 1):
        if alumnos[j][1] < alumnos[j+1][1]:
            alumnos[j], alumnos[j+1] = alumnos[j+1], alumnos[j]
        elif alumnos[j][1] == alumnos[j+1][1] and alumnos[j][0] > alumnos[j+1][0]:
            alumnos[j], alumnos[j+1] = alumnos[j+1], alumnos[j]

for a in alumnos:
    print(a)
