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

    # print(pos,pr[pos])
    # print(posi,pr[posi])

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

    # print(effect_dict[182419])
    # print(pr[182419])


    ES = [effect_dict[app] for app in effect_dict]

    # ES = sorted(ES)

    PR = [pr[app] if app in pr else 0.0 for app in effect_dict]

    list_tot = []
    for i in range(len(ES)):
        list_tot.append([ES[i], PR[i]])

    list_tot = sorted(list_tot, key=lambda x:x[0])

    mx2 = list_tot[0][0]
    mx = list_tot[1][1]
    print(mx)

    ES2 = []
    PR2 = []

    n = len(list_tot)
    print(n)
    print(list_tot[0:5])
    print(max(list_tot[:][1]))

    CC2 = []
    for i in range(n):
        CC2.append(list_tot[i][1])
    CC1 = CC2[:int(0.2 * n)]

    print(CC1[0:5])


    ecdf = sm.distributions.ECDF(CC1)
    # print(ecdf)
    x = np.linspace(0, 0.00001)
    y = ecdf(x)
    plt.ylim(0, 1)
    plt.plot(x, y, linewidth='1', marker='o', label='pagerank with constraint_min20% cdf')

    ecdf2 = sm.distributions.ECDF(CC2)

    x = np.linspace(0, 0.00001)
    y = ecdf2(x)
    plt.ylim(0, 1)
    plt.plot(x, y, linewidth='1', marker='o', label='pagerank-non-SHS cdf')

    plt.xlabel('pagerank')
    plt.ylabel('CDF')
    plt.title('pagerank CDF')
    plt.legend(loc=0, ncol=1)
    plt.show()
