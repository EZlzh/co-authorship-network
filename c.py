import matplotlib.pyplot as plt
import numpy as np
import statsmodels.api as sm


if __name__ == '__main__':
    sum = 0
    list_nodes_values = []
    mx = 0
    with open("output1.txt", "r") as f1:
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
    betweenness_dict = {}
    for node in list_nodes_values:
        betweenness_dict[node[0]-1] = node[1]

    for node in range(mx):
        if node not in betweenness_dict:
            betweenness_dict[node] = 0.000000
        #   print(node)
    # print(betweenness_dict)


    BC = [betweenness_dict[app] for app in range(mx)]
    # print(BC[-1])
    CC = sorted(BC, reverse=True)
    # print(CC[4990:5000])
    ecdf = sm.distributions.ECDF(BC)
    # print(ecdf)
    print(max(BC))
    x = np.linspace(0, max(BC)/1000)
    y = ecdf(x)
    plt.ylim(0, 1)
    plt.plot(x, y, linewidth='1', marker='o', label='BC cdf')
    plt.xlabel('BC')
    plt.ylabel('CDF')
    plt.title('BC CDF')
    plt.show()
