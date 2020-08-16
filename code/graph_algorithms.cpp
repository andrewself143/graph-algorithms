#include "graph.h"
#include <iterator>
#include <iostream>
using namespace std;

int get_diameter(Graph graph)
{


	auto it = graph.nodes.begin();
	advance(it, rand() % graph.nodes.size());

	int maxD = 0;

	Node temp = it->first;

	for(int i = 0; i < 10; i++) {
		pair<Node,int> first = graph.bfs(temp);
		//cout << "\nDiam: " << first.second << "\n";
		if (first.second > maxD) {
			maxD = first.second;
		}
		temp = first.first;
	}


	return maxD;

}

float get_clustering_coefficient(Graph graph)
{
	int num_t = graph.num_tri();
	int num2 = graph.num_2_edge();
	float ce = (3.0 * num_t) / num2;
	return ce;
}

std::map<int, int> get_degree_distribution(Graph graph)
{

	map<int,int> dist;
	for (map<Node, vector<Node>>::iterator iter = graph.nodes.begin(); iter != graph.nodes.end(); iter++) {
		int deg = iter->second.size();
		if (dist.find(deg) == dist.end() ) {
			dist[deg] = 1;
		} else {
			dist[deg] = dist[deg] + 1;
		}
	}

	return dist;

}
