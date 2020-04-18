import snap

if __name__ == '__main__':
    list_nodes = []
    with open ("nodes.txt","r") as f1:
        lines = f1.readlines()
        for line in lines:
            list_nodes.append(int(line))
    n = len(list_nodes)
    print(n)

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
    print('图中的边数:',sum)

    
    G = snap.TUNGraph.New()
    for node in list_nodes:
        G.AddNode(node)
    
    for edge in list_edges:
        G.AddEdge(edge[0],edge[1])
    

    Nodes = snap.TIntFltH()
    Edges = snap.TIntPrFltH()
    snap.GetBetweennessCentr(G, Nodes, Edges, 1.0)

    