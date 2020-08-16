#ifndef GRAPH_ALGS_H
#define GRAPH_ALGS_H



#include <vector>
#include <map>
#include "graph.h"

Graph make_graph(int num_nodes, std::vector<int> u, std::vector<int> v);



int get_diameter(Graph graph);
float get_clustering_coefficient(Graph graph);
std::map<int, int> get_degree_distribution(Graph graph);

#endif
