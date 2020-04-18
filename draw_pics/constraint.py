import matplotlib.pyplot as plt
import numpy as np
import statsmodels.api as sm


if __name__ == '__main__':
    sum = 0
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

    print(list_nodes_values[1:5])
    print(mx)
    mx = 402392
    # print(len(list_edges))
    constraint_dict = {}
    for node in list_nodes_values:
        constraint_dict[node[0]-1] = node[1]

    # for node in range(mx):
    #     if node not in constraint_dict:
    #         constraint_dict[node] = 0.000000
    #     #   print(node)
    # # print(betweenness_dict)


    CT = [constraint_dict[app] for app in constraint_dict]
    # print(BC[-1])
    CC = sorted(CT)
    n = len(CT)
    CC1=CC[:int(0.2*n)]
    CC2=CC[int(0.2*n):]
    # print(CC[4990:5000])

    ecdf = sm.distributions.ECDF(CC1)
    # print(ecdf)
    print(max(CT))
    x = np.linspace(0, max(CT))
    y = ecdf(x)
    plt.ylim(0, 1)
    plt.plot(x, y, linewidth='1', marker='o', label='Constraint-20% cdf')

    ecdf2 = sm.distributions.ECDF(CC2)
    print(max(CT))
    x = np.linspace(0, max(CT))
    y = ecdf2(x)
    plt.ylim(0, 1)
    plt.plot(x, y, linewidth='1', marker='o', label='Constraint-non-SHS cdf')

    plt.xlabel('Constraint')
    plt.ylabel('CDF')
    plt.title('Constraint CDF')
    plt.legend(loc=0,ncol=1)
    plt.show()
