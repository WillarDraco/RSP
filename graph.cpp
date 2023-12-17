#include <iostream>
#include <list>

class graph {
    int vertices;
    std::list<int> *l;
    public:
        graph(int vertices){
            this->vertices = vertices;
            l = new std::list<int>[vertices];
        }

        void addEdge(int x, int y) {
            l[x].push_back(y);
            l[y].push_back(x);
        }

        void printAdjList() {
            for (int i = 0; i < vertices; i++) {
                std::cout << "Vertex: " << i << " ";
                for (auto it:l[i]) {
                    std::cout << it << ", ";
                }
                std::cout << std::endl;
            }
        }
};

int main(void) {
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);

    g.printAdjList();
}