template <typename NameType, typename T> class Graph;
template <typename NameType, typename T> class EdgeNode {
    friend class Graph<NameType, T>;
    private:
        int dest;
        T cost;
        EdgeNode<NameType, T> *link;
    public:
        EdgeNode() {}
        EdgeNode(int d, T c): dest(d), cost(c), link(nullptr) {}
};
template <typename NameType, typename T> class VertexNode {
    friend class EdgeNode<NameType, T>;
    friend class Graph<NameType, T>;
    NameType data;
    EdgeNode<NameType, T> *adj;
};
template <typename NameType, typename T> class Graph {
    private:
        Vertex<NameType, T> *NodeTable;
        int VerticesNumber;
        int VerticesMaxNumber;
        int EdgesNumber;
        int GetVertexPosition(const NameType &vertex);
};;

