#include <cstddef>
#include <utility>
using namespace std;
struct pair_hash {
    inline size_t operator()(const pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
