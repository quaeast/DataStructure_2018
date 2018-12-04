import numpy as np

def work():
    x, y = map(int, raw_input().strip().split())
    if (x == 0 and y == 0):
        return 0
    graph = np.zeros([x + 1, x + 1], dtype=int)
    result = np.zeros([x + 1, x + 1], dtype=int)

    for i in range(y):
        a, b = map(int, raw_input().strip().split())
        graph[a][b] = 1;
        graph[b][a] = 1;

    temp = np.copy(graph)

    for i in range(5):
        temp = np.matmul(temp, graph)
        result = result + temp

    # print result

    for i in range(1, x + 1):
        re = 0
        for j in range(1, x + 1):
            if (result[i][j] != 0):
                re += 1
        print ("%d%s%.2f%s" %(i, ': ', 100*re/x, '%'))
    return 1

while(1):
    if(not work()):
        break