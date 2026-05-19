#include <iostream>
using namespace std;

#define V 5

// Function to check whether vertex v can be added
bool isSafe(int v, int graph[V][V], int path[], int pos) {

    // Check if current vertex is connected
    // with previous vertex
    if(graph[path[pos - 1]][v] == 0)
        return false;

    // Check if vertex already exists in path
    for(int i = 0; i < pos; i++) {

        if(path[i] == v)
            return false;
    }

    return true;
}

// Backtracking function
bool hamiltonianCycleUtil(int graph[V][V],
                          int path[],
                          int pos) {

    // If all vertices are included
    if(pos == V) {

        // Check if last vertex connects to first
        if(graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // Try different vertices
    for(int v = 1; v < V; v++) {

        if(isSafe(v, graph, path, pos)) {

            path[pos] = v;

            // Recursive call
            if(hamiltonianCycleUtil(graph,
                                    path,
                                    pos + 1))
                return true;

            // Backtrack
            path[pos] = -1;
        }
    }

    return false;
}

// Main Hamiltonian Cycle function
bool hamiltonianCycle(int graph[V][V]) {

    int path[V];

    // Initialize path with -1
    for(int i = 0; i < V; i++)
        path[i] = -1;

    // Start from vertex 0
    path[0] = 0;

    if(!hamiltonianCycleUtil(graph,
                             path,
                             1)) {

        cout << "No Hamiltonian Cycle exists";

        return false;
    }

    // Print solution
    cout << "Hamiltonian Cycle is:\n";

    for(int i = 0; i < V; i++)
        cout << path[i] << " ";

    // Print starting vertex again
    cout << path[0];

    return true;
}

int main() {

    int graph[V][V] = {

        {0, 1, 0, 1, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 0, 1, 1, 0}
    };

    hamiltonianCycle(graph);

    return 0;
}