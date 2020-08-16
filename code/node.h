#ifndef NODE_H
#define NODE_H

class Node {
	public:
		bool operator==(const Node& other) const {return id == other.id;} 	// used for comparing two nodes, already implemented
		int id; 															// uniquely identifies a node (no two nodes have the same id).
																				 // id must be set in the constructor and thereafter not modified
		Node(){}															// don't use this constructor, implement another one that accepts node id as an argument
		Node(int nid);

		bool operator <(const Node& rhs) const;
		//bool operator ==(const Node& p) const;



};

#endif
