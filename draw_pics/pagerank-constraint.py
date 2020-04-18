import matplotlib.pyplot as plt
import numpy as np
import statsmodels.api as sm
import matplotlib as mpl
from scipy.interpolate import make_interp_spline

if __name__ == '__main__':
    sum = 0

    list_nodes_values0 = []
    mx = 0
    with open("1.txt", "r") as f1:
        lines = f1.readlines()
        for line in lines:
            connection = line.strip().split(" ")
            sum += 1
            # if sum == 1:
            #     print(connection)
            list_nodes_values0.append([int(connection[0]), float(connection[1])])
            mx = max(mx, int(connection[0]))

    # print(list_nodes_values[1:5])
    # print(mx)
    # print(list_nodes_values[1][1]+list_nodes_values[2][1])

    pr = {}
    mx = 0
    mi = 1
    for node in list_nodes_values0:
        pr[node[0]] = node[1]
        if node[1] > mx:
            pos = node[0]
            mx = node[1]
        if node[1]< mi:
            mi = node[1]
            posi = node[0]

    print(pos,pr[pos])
    print(posi,pr[posi])

    list_nodes_values = []
    mx = 0
    with open("output_constraint.txt", "r") as f1:
        lines = f1.readlines()
        for line in lines:
            connection = line.strip().split(" ")
            sum += 1
            # if sum == 1:
            #     print(connection)
            list_nodes_values.append([int(connection[0]), float(connection[1])])
            mx = max(mx, int(connection[0]))

    # print(list_nodes_values[1:5])
    # print(mx)
    mx = 402392
    # print(len(list_edges))
    effect_dict = {}
    for node in list_nodes_values:
        effect_dict[node[0]-1] = node[1]

    print(effect_dict[182419])
    print(pr[182419])


    ES = [effect_dict[app] for app in effect_dict]

    # ES = sorted(ES)

    PR = [pr[app] if app in pr else 0.0 for app in effect_dict]

    list_tot = []
    for i in range(len(ES)):
        list_tot.append([ES[i], PR[i]])

    list_tot = sorted(list_tot, key=lambda x:x[0])



    ES2 = []
    PR2 = []

    n = len(list_tot)

    res = 0.0
    num = 0
    for i in range(n):
        if i != n-1 and list_tot[i][0]==list_tot[i+1][0]:
            res += list_tot[i][1]
            num += 1
        else:
            res += list_tot[i][1]
            num += 1
            ES2.append(list_tot[i][0])
            PR2.append(res/num)
            res = 0.0
            num = 0

    x = np.array(ES2)
    # print(x[1:5])
    y = np.array(PR2)

    plt.plot(x, y, linewidth='1', marker='o', label='pagerank-constraint')

    plt.xlabel('constraint')
    plt.ylabel('pagerank')
    plt.title('pagerank-contraint')

    # mpl.rcParams['agg.path.chunksize'] = 300000

    plt.show()
