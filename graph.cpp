#include <iostream>
#include <list>
#include <vector>
#include <map>

class graph {
    int vertices;
    std::list<int> *adj;
    bool *visited;
    public:
        graph(int vertices){
            this->vertices = vertices;
            adj = new std::list<int>[vertices];
            visited = new bool[vertices];
        }

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

        void BFS(int s) {
            std::vector<bool> visited;
            visited.resize(vertices, false);

            std::list<int> queue;
            visited[s] = true;
            queue.push_back(s);

            while (!queue.empty()) {
                s = queue.front();
                std::cout << s << " ";
                queue.pop_front();

                for (auto adjacent : adj[s]) {
                    if (!visited[adjacent]) {
                        visited[adjacent] = true;
                        queue.push_back(adjacent);
                    }
                }
            }
        }

        void DFS(int s) {
            visited[s] = true;
            std::list<int> DFSadj = adj[s];
            std::cout << s << " ";

            for (auto i = DFSadj.begin(); i != DFSadj.end(); i++) {
                if (!visited[*i]) {
                    DFS(*i);
                }
            }
            return;
        }
};

int main(void) {
    graph g(4);
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