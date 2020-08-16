#ifndef GRAPH_H
#define GRAPH_H
#include <map>
#include <vector>
#include "node.h"
#include <unordered_set>
#include "hash.cpp"

using namespace std;

class Graph
{
	public:

				int get_num_nodes(); 						// get number of nodes
				int get_num_edges(); 						// get number of edges
				std::vector<Node> get_neighbors(Node u); 	// return neighbors of u
				std::map<int, Node> get_id_to_node_map(); 	// allows lookup of nodes from ids

	Graph();
	void add_node(int i);
	void add_edge(int l, int r);
	pair<Node,int> bfs(Node n);
	int num_2_edge();
	int num_tri();
	pair<vector<Node>, map<int,vector<Node>>> degen();

	map<Node, vector<Node>> nodes;
	map<int, Node> nm;

	unordered_set<pair<int,int>, pair_hash> edges;

		
};

#endif
