#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 6;
char nodes[SIZE] = {'U', 'V', 'W', 'X', 'Y', 'Z'};

int graph[SIZE][SIZE];

bool visited[SIZE];
int discover[SIZE];
int finish[SIZE];
int timeCounter = 0;

int getIndex(char ch) {
    for (int i = 0; i < SIZE; i++) {
        if (nodes[i] == ch) return i;
    }
    return -1;
}

void addEdge(char from, char to) {
    int u = getIndex(from);
    int v = getIndex(to);
    graph[u][v] = 1;
}

void dfs(int u) {
    visited[u] = true;
    timeCounter++;
    discover[u] = timeCounter;

    for (int v = 0; v < SIZE; v++) {
        if (graph[u][v] == 1) {
            if (!visited[v]) {
                cout << nodes[u] << " -> " << nodes[v] << " : Tree Edge\n";
                dfs(v);
            } else if (finish[v] == 0) {
                cout << nodes[u] << " -> " << nodes[v] << " : Back Edge\n";
            } else {
                cout << nodes[u] << " -> " << nodes[v] << " : Cross Edge\n";
            }
        }
    }

    timeCounter++;
    finish[u] = timeCounter;
}

void startDFS() {
    memset(visited, false, sizeof(visited));
    timeCounter = 0;

    for (int i = 0; i < SIZE; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    cout << "\nNode\tDiscovery\tFinish\n";
    for (int i = 0; i < SIZE; i++) {
        cout << nodes[i] << "\t" << discover[i] << "\t\t" << finish[i] << endl;
    }
}

int main() {
    memset(graph, 0, sizeof(graph));

    addEdge('U', 'V');
    addEdge('U', 'X');
    addEdge('V', 'X');
    addEdge('V', 'Y');
    addEdge('W', 'Y');
    addEdge('W', 'Z');
    addEdge('X', 'Y');
    addEdge('Z', 'Z');

    startDFS();

    return 0;
}
