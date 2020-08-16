#include "graph.h"
#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;




Graph make_graph(int num_nodes, std::vector<int> u, std::vector<int> v){


	Graph graph;

	for(int i = 1; i <= num_nodes; i++) {
		graph.add_node(i);
	}

	for(int i = 0; i < v.size(); i++) {
		int l = u[i];
		int r = v[i];

		// only add if new
		pair<int,int> edge;
		edge = make_pair(l, r);
		unordered_set<pair<int,int>, pair_hash>::const_iterator got = graph.edges.find(edge);
		if (got == graph.edges.end()) {
			graph.add_edge(l,r); //only add new edges
		}


	}

	return graph; //
}

Graph::Graph() {
	map<Node, vector<Node>> test;
	nodes = test;
}

void Graph::add_node(int i) {

	pair<Node, vector<Node>> p1;
	Node n1 = Node(i);
	vector<Node> v1;
	p1.first = n1;
	p1.second = v1;
	nodes.insert(p1);
	nm[i] = n1;
}

void Graph::add_edge(int l, int r) {
	/*for (map<Node, vector<Node>>::iterator iter = nodes.begin(); iter != nodes.end(); iter++) {
		if (iter->first.id == l) {
			iter->second.push_back(r);
		}
	}*/

	Node n1 = nm[l];
	nodes[n1].push_back(r);

	/*for (map<Node, vector<Node>>::iterator iter = nodes.begin(); iter != nodes.end(); iter++) {
		if (iter->first.id == r) {
			iter->second.push_back(l);
		}
	}*/

	Node n2 = nm[r];
	nodes[n2].push_back(l);

	pair<int,int> edge;
	edge = make_pair(l, r);
	edges.insert(edge);

	// add reverse too
	pair<int,int> edge2;
	edge2 = make_pair(r, l);
	edges.insert(edge2);
}

pair<Node,int> Graph::bfs(Node n) {
	vector<Node> visited;
	queue<Node> to_visit;

	map<Node, int> dict;
	dict[n] = 0;

	to_visit.push(n);
	visited.push_back(n);

	//cur_dist = 0;

	Node last;
	int lastD;

	while (to_visit.size() != 0) {

		//cout << "\nto visit size: "  << to_visit.size();

		Node cur = to_visit.front();
		to_visit.pop();

		//cout << "\nto visit size: " << to_visit.size();


		//cout << "\n cur node: " << cur.id << "\n";



		//visited.push_back(cur);

		for(int i = 0; i < nodes[cur].size(); i++) {
			vector<Node>::iterator it;
			it = std::find(visited.begin(),visited.end(),nodes[cur][i]);
			//it2 = std::find(to_visit.begin(),to_visit.end(),nodes[cur][i]);
			if (it == visited.end()) {
				//cout << "\nvisited id's: ";
				for(int i = 0; i < visited.size(); i++) {
					//cout << visited[i].id << " ";
				}
				//cout << "\nInside new node with new node: " << nodes[cur][i].id;
				to_visit.push(nodes[cur][i]);

				visited.push_back(nodes[cur][i]);

				dict[nodes[cur][i]] = dict[cur] + 1;
			}
			/*cout << "\nvisited id's: ";
			for(int i = 0; i < visited.size(); i++) {
				cout << visited[i].id << " ";
			}*/
		}



		last = cur;



		lastD = dict[cur];

		//cout << "\n last D: " << lastD << "\n";
		//cout << "\n cur node: " << cur.id << "\n";
	}

	pair<Node,int> end;
	end.first = last;
	end.second = lastD;
	return end;

}

int Graph::num_2_edge() {
	int sum = 0;
	for (map<Node, vector<Node>>::iterator iter = nodes.begin(); iter != nodes.end(); iter++) {
		int deg = iter->second.size();
		int val = deg * (deg-1) / 2;
		sum = sum + val;
	}
	return sum;
}

int Graph::num_tri() {
	int count = 0;
	pair<vector<Node>, map<int,vector<Node>>> p = degen();
	vector<Node> L = p.first;
	map<int,vector<Node>> N = p.second;

	for(int i = 0; i < L.size(); i++) {
		int id = L[i].id;
		for(int j = 0; j < N[id].size(); j++) {
			for(int k = 0; k < N[id].size(); k++) {
				pair<int,int> edge;
				edge = make_pair(N[id][j].id, N[id][k].id);
				unordered_set<pair<int,int>, pair_hash>::const_iterator got = edges.find(edge);
				if (got != edges.end()) {
					count++;
				}
			}
		}
	}

	return count;
}

pair<vector<Node>, map<int,vector<Node>>> Graph::degen() {
	// 1. L
	vector<Node> L;
	// 2. compute dv
	map<Node,int> dv;
	int max = 0;
	for (map<Node, vector<Node>>::iterator iter = nodes.begin(); iter != nodes.end(); iter++) {
		int deg = iter->second.size();
		dv[iter->first] = deg;
		if (deg > max) {
			max = deg;
		}
	}
	// 3.
	//vector<vector<Node>> D;
	map<int,vector<Node>> D;
	//fill empy vectors
	for(int i = 0; i++; i < max) {
		vector<Node> temp;
		D[i] = temp;
	}
	for (map<Node, int>::iterator iter = dv.begin(); iter != dv.end(); iter++) {
		//cout << "tes" ;
		D[iter->second].push_back(iter->first);
	}
	// 4.
	map<int,vector<Node>> N;
	for (int i = 0; i < nodes.size(); i++) {
		vector<Node> temp;
		N[i] = temp;
	}
	// 5.
	int k = 0;
	//6

	unordered_set<int> H;
	for (int j = 0; j < nodes.size(); j++) {
		//smallest nonempty D
		int i = 0;
		while (i < D.size()) {
			if (not D[i].empty()) {
				break;
			}
			i++;
		}
		// k = max (i,k)
		if (i > k) {
			k = i;
		}
		Node cur = D[i].back();
		D[i].pop_back();
		L.push_back(cur);
		H.insert(cur.id);
		//iterate through neighbors
		for (int i = 0; i < nodes[cur].size(); i++) {
			Node w = nodes[cur][i];
			unordered_set<int>::const_iterator got = H.find(w.id);
			if (got == H.end()) { // Not in L
				dv[w] = dv[w] - 1; // subtract 1 from dw
				D[dv[w]].push_back(w); //add to new D
				// remove from old D?
				int r = 0;
				while ( true) {
					if (D[dv[w]+1][r] == w) {
						D[dv[w]+1].erase( D[dv[w]+1].begin() + r);
						break;
					}
					r++;
				}
				N[cur.id].push_back(w);
			}
		}
	}

	pair<vector<Node>, map<int,vector<Node>>> end;
	end.first = L;
	end.second = N;
	return end;

}

int Graph::get_num_nodes() {


	return nodes.size();


}

int Graph::get_num_edges() {

	int sum = 0;
	for (map<Node, vector<Node>>::iterator iter = nodes.begin(); iter != nodes.end(); iter++) {

		//cout << "\nInt Vector:  "  << iter->second.size() << "\n";

		sum = sum + iter->second.size();
	}

	sum = sum/2;

	return sum;


}

std::vector<Node> Graph::get_neighbors(Node u) {

	return nodes[u];

	//return std::vector<Node>{}; //
}

std::map<int, Node>Graph::get_id_to_node_map(){
	map<int, Node> ids;
	for (map<Node, vector<Node>>::iterator iter = nodes.begin(); iter != nodes.end(); iter++) {
		pair<int, Node> p1;
		p1.first = iter->first.id;
		p1.second = iter->first;
		ids.insert(p1);
	}
	return ids;
	//return std::map<int, Node>{}; // 
}
