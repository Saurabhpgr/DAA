#include <iostream>
using namespace std;

#define V 4

// Function to check if color can be assigned
bool isSafe(int graph[V][V],
            int color[],
            int vertex,
            int c) {

    for(int i = 0; i < V; i++) {

        if(graph[vertex][i] == 1 &&
           color[i] == c) {

            return false;
        }
    }

    return true;
}

// Backtracking function
bool graphColoringUtil(int graph[V][V],
                       int m,
                       int color[],
                       int vertex) {

    // All vertices colored
    if(vertex == V)
        return true;

    // Try all colors
    for(int c = 1; c <= m; c++) {

        if(isSafe(graph, color, vertex, c)) {

            color[vertex] = c;

            // Recur for next vertex
            if(graphColoringUtil(
                graph, m, color, vertex + 1))
                return true;

            // Backtrack
            color[vertex] = 0;
        }
    }

    return false;
}

// Print solution
void printSolution(int color[]) {

    cout << "Color Assignment:\n";

    for(int i = 0; i < V; i++) {

        cout << "Vertex "
             << i
             << " ---> Color "
             << color[i]
             << endl;
    }
}

int main() {

    int graph[V][V] = {

        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };

    int m = 3; // Number of colors

    int color[V] = {0};

    if(graphColoringUtil(graph,
                         m,
                         color,
                         0)) {

        printSolution(color);
    }

    else {

        cout << "Solution does not exist";
    }

    return 0;
}