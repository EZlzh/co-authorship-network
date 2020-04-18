import matplotlib.pyplot as plt
import numpy as np
import statsmodels.api as sm


if __name__ == '__main__':
    sum = 0
    list_nodes_values = []
    mx = 0
    with open("output_effective_size.txt", "r") as f1:
        lines = f1.readlines()
        for line in lines:
            connection = line.strip().split(" ")
            sum += 1
            # if sum == 1:
            #     print(connection)
            list_nodes_values.append([int(connection[0]), float(connection[1])])
            mx = max(mx, int(connection[0]))

    print(list_nodes_values[1:5])
    print(mx)
    mx = 402392
    # print(len(list_edges))
    effect_dict = {}
    for node in list_nodes_values:
        effect_dict[node[0]-1] = node[1]

    # list_nodes_values2 = []
    # with open("output_constraint.txt", "r") as f2:
    #     lines = f2.readlines()
    #     for line in lines:
    #         connection = line.strip().split(" ")
    #         list_nodes_values2.append([int(connection[0]), float(connection[1])])
    #         mx = max(mx, int(connection[0]))
    #
    # for node in list_nodes_values2:
    #     effect_dict[node[0]-1] /= node[1]


    ES = [effect_dict[app] for app in effect_dict]
    # print(BC[-1])
    CC = sorted(ES, reverse=True)
    # print(CC[4990:5000])
    ecdf = sm.distributions.ECDF(ES)
    # print(ecdf)
    print(max(ES))
    x = np.linspace(0, max(ES)/10)
    y = ecdf(x)
    plt.ylim(0, 1)
    plt.plot(x, y, linewidth='1', marker='o', label='Effective_size cdf')
    plt.xlabel('Effective_size')
    plt.ylabel('CDF')
    plt.title('Effective_size CDF')
    plt.show()
