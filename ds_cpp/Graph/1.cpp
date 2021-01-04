#include <iostream>
#include <vector>



// list
template<typename T> class Graph {
    private:
        
    public:
        bool InsertVertex();
        bool InsertEdge(int v1, int v2);
        int GetWeight(int v1, int v2);
        
};

int main() {
    Graph<int> g;
    return 0;
}
