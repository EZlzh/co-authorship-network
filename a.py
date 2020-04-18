import networkx as nx
import matplotlib.pyplot as plt
import numpy as np
import statsmodels.api as sm
import community as community_louvain

if __name__ == '__main__':
    list_nodes = []
    with open ("nodes.txt","r") as f1:
        lines = f1.readlines()
        for line in lines:
            list_nodes.append(int(line))
    n = len(list_nodes)
    # print(n)
    G = nx.Graph()
    for node in list_nodes:
        G.add_node(node)
    print('图中节点的个数', G.number_of_nodes())

    sum = 0
    list_edges = []
    with open ("edges.txt","r") as f1:
        lines = f1.readlines()
        for line in lines:
            connection = line.strip().split(",")
            sum+=1
            # if sum == 1:
            #     print(connection)
            list_edges.append((int(connection[0]), int(connection[1])))
    # print('图中的边数:', print(sum))
    # print(list_edges[0])

    G.add_edges_from(list_edges)
    print('图中边的个数:', G.number_of_edges())

    # sum = 0
    # for edge in G.edges:
    #     print(edge[0],edge[1])
    #     sum+=1
    #     if sum==5:
    #         break

    p_r = nx.pagerank(G, alpha=0.85)
    with open("1.txt", "w") as f:
        for i in p_r:
            f.write(str(i) + " " + str(p_r[i]) + "\n")


    # PR = [p_r[app] for app in G.nodes()]
    # ecdf = sm.distributions.ECDF(PR)
    # x = np.linspace(0, max(PR))
    #
    # print(max(PR))
    #
    # y = ecdf(x)
    # plt.plot(x, y, linewidth='2', marker='o', label='Pagerank cdf')
    # plt.xlabel('Pagerank')
    # plt.ylabel('CDF')
    # plt.title('Pagerank CDF')
    # plt.show()



    # B_C = nx.betweenness_centrality(G)

    # BC = [B_C[app] for app in G.nodes()]
    # ecdf = sm.distributions.ECDF(BC)
    # x = np.linspace(0, max(BC))
    # y = ecdf(x)
    # plt.plot(x, y, linewidth='2', marker='o', label='BC cdf')
    # plt.xlabel('BC')
    # plt.ylabel('CDF')
    # plt.title('BC CDF')
    # plt.show()

    # constraint_dict = nx.constraint(G)
    # effective_size = nx.effective_size(G)



    # first compute the best partition
    # partition = community_louvain.best_partition(G)
    # # size = float(len(set(partition.values())))
    # # print(size)
    #
    # # drawing
    # size = float(len(set(partition.values())))
    # pos = nx.spring_layout(G)
    # count = 0.
    # for com in set(partition.values()):
    #     count = count + 1.
    #     list_nodes = [nodes for nodes in partition.keys()
    #                   if partition[nodes] == com]
    #     nx.draw_networkx_nodes(G, pos, list_nodes, node_size=20,
    #                            node_color=str(count / size))
    #
    # nx.draw_networkx_edges(G, pos, alpha=0.5)
    # plt.show()