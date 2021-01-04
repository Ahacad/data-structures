#include <iostream>
#include <queue>
#include <vector>

int dijkstra(std::vector< std::vector< std::pair<int, int> > > *adj, int s, int t ) {
    std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > q;
    q.push(std::make_pair(0, s));
    int n = adj->size();
    std::vector<int> d(n, INT32_MIN);
    while (!q.empty()) {
        int currentNode =  q.top().second;
        int currentDist = q.top().first;
        q.pop();
        for (std::pair<int, int> edge : (*adj)[currentNode]) {
            if (currentDist + edge.second < d[edge.first]) {
                d[edge.first] = currentDist + edge.second;
                q.push(std::make_pair(d[edge.first], edge.second));
            }
        }
    }
    if (d[t] != INT32_MIN) {
        return d[t];
    }
    return -1;
}

int main() {
    return 0;
}
