#include <iostream>
#include <list>
#include <vector>
#include <map>

class graph {
    int vertices;
    std::map<int, bool> visited;
    std::map<int, std::list<int> > adj;
    public:
        void addEdge(int x, int y) {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        void printAdjList() {
            for (int i = 0; i < vertices; i++) {
                std::cout << "Vertex: " << i << " ";
                for (auto it:adj[i]) {
                    std::cout << it << ", ";
                }
                std::cout << std::endl;
            }
        }

        void DFS(int s) {

            visited[vertices] = true;
            std::cout << vertices << " ";

            std::list<int>::iterator i;
            for (i = adj[vertices].begin(); i != adj[vertices].end(); i++) {
                if (!visited[*i]) {
                    DFS(*i);
                }
            }
        }
};

int main(void) {
    graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);

    // std::cout << "Following is Breadth First Traversal "
    //      << "(starting from vertex 2) \n";
    // g.BFS(2);
 

    std::cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
 
    // Function call
    g.DFS(2);
 
    return 0;
    return 0;
}