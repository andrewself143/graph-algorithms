#include "node.h"



Node::Node(int nid) {
	id = nid;
}

bool Node::operator <(const Node& rhs) const {
	return id < rhs.id;
}

/*bool Node::operator ==(const Node& p) const {
	return id == p.id;
}*/
