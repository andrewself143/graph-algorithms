#include "graph-algs.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sodium.h>
#include <algorithm>
#include "barabasi.cpp"

using namespace std;

int main(int argc, char* argv[]) {
	//cout << "Hello\n";

	pair<vector<int>,vector<int>> g;

	int num = atoi(argv[1]);

	g = barabasi(num,5);

	/*for(int i = 0; i < g.first.size(); i++) {
		cout << g.first[i] << " " << g.second[i] << "\n";

	}*/

	Graph graph;
	graph = make_graph(num, g.first, g.second);
	//cout << "graph made\n";
	//cout << "diam: " << get_diameter(graph) << "\n";
	//cout << num << " " << get_diameter(graph) << "\n";
	//cout << "clust: " << get_clustering_coefficient(graph) << "\n";
	//cout << num << " " << get_clustering_coefficient(graph) << "\n";
	map<int, int> dist = get_degree_distribution(graph);

	for(map<int,int>::iterator it = dist.begin(); it != dist.end(); it++) {
		cout << it->first << " " << it->second << "\n";
	}

	//cout << "deg dist" << "\n";


	return 0;
}
