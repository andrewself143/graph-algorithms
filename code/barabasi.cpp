
#include <sodium.h>
#include <iostream>

using namespace std;

pair<vector<int>,vector<int>> barabasi(int n, int d) {

	vector<int> M(2*n*d, 0);

	vector<int> E1;
	vector<int> E2;

	for(int v = 0; v < n; v++) {
		for(int i = 0; i < d; i++) {
			M[2*(v*d + i)] = v;
			int r = randombytes_uniform(2*(v*d + i)+1);
			M[2*(v*d + i)+1] = M[r];
		}
	} 

	for(int i = 0; i < (n*d) - 1; i++) {
		E1.push_back(M[2*i]+1); // add extra 1 to each for nodes starting at 1
		E2.push_back(M[(2*i)+1]+1);
	}

	pair<vector<int>,vector<int>> p1;
	p1.first = E1;
	p1.second = E2;

	return p1; 
}
