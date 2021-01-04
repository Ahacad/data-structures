template <typename NodeName, typename WeightType> class Graph;
template <typename NodeName, typename WeightType> class VertexNode {
    friend class Graph<NodeName, WeightType>;
    
};

template <typename NodeName, typename WeightType> class Graph {
    private:
        VertexNode<NodeName, WeightType> *nodeTable;
        int verticesNumber;
        int verticesMaxNumber = -1;
        int edgeNumber;
    public:
        bool Empty() const {
            return verticesNumber == 0;
        }
        bool Full() const {
            return verticesNumber == verticesMaxNumber;
        }
        int VerticesNumber() const {
            return verticesNumber;
        }
        int EdgeNumber() const {
            return edgeNumber;
        }
        // get weight of an edge
        WeightType GetWeight(int v1, int v2);
        int GetFirstNeighbor(int v);
        int GetNextNeighbor(int v);
        bool InsertVertex(const NodeName v);
        bool InsertEdge(int v1, int v2, WeightType cost);
        bool RemoveVertex(const NodeName v);
        bool RemoveVertex(int v1, int v2);
};;

