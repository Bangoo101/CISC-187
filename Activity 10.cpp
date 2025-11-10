#include <iostream>
using namespace std;
// beadth search and depth first search tree structure
//looked it up online
class Graph {
    private:
        int adjMatrix[6][6];
        char nodes[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
        int size = 6;
    public:
        Graph() {
            // initialize adjacency matrix to 0
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    adjMatrix[i][j] = 0;
                }
            }
        }

        void addEdge(char FROM, char TO) {
            int i = getIndex(FROM);
            int j = getIndex(TO);
            if (i != -1 && j != -1){
                adjMatrix[i][j] = 1;
                adjMatrix[i][j] = 1;
            }
        }

        int getIndex(char node) {
            for (int i = 0; i < size; i++) {
                if (nodes[i] == node) {
                    return i;
                }
            }
            return -1; // node not found
        }

        void BFS(char start) {
            bool visited[6] = {false}; 
            char queue[6];
            int front = 0, rear = 0; //rear is the starting

            int startIndex = getIndex(start);
            visited[startIndex] = true;
            queue[rear++] = start;
            cout<< "BFS Traversal: ";
            while(front < rear){ // goes trhough full list
                char current = queue[front++];
                cout<< current<< " ";
                int currentIndex = getIndex(current);
                for (int i = 0; i < size; i++){
                    if (adjMatrix[currentIndex][i] == 1 && !visited[i]){
                        visited[i] = true;
                        queue[rear++] = nodes[i];
                    }
                }
            }
            cout << endl;
        } 

        void DFS(char start){
            bool visited[6] = {false};
            cout << "DFS Traveral: ";
            DFSHelper(start, visited); 
            cout<< endl;
        }

        void DFSHelper(char node, bool visited[]){
            int index = getIndex(node); 
            visited[index] = true;
            cout<< node << " ";
            for (int i = 0;  i < size; i++){
                if (adjMatrix[index][i] == 1 && !visited[i])
                    DFSHelper(nodes[i], visited);
            }
        }
}; // end of graph class

int main(){
    Graph g;

    g.addEdge('A','B');
    g.addEdge('A','F');
    g.addEdge('B','C');
    g.addEdge('C','D');
    g.addEdge('C','E');

    g.BFS('A');
    g.DFS('A');

    return 0;
}
