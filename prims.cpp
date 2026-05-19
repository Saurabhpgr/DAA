#include <iostream>
using namespace std;

#define V 5

int main() {

    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    bool selected[V];

    // Initially no vertex is selected
    for(int i = 0; i < V; i++) {
        selected[i] = false;
    }

    selected[0] = true;

    int edge_count = 0;
    int total_cost = 0;

    cout << "Selected Edges:\n";

    while(edge_count < V - 1) {

        int minimum = 999;
        int x = 0;
        int y = 0;

        for(int i = 0; i < V; i++) {

            if(selected[i]) {

                for(int j = 0; j < V; j++) {

                    if(!selected[j] && graph[i][j]) {

                        if(minimum > graph[i][j]) {
                            minimum = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x << " - " << y
             << " : " << graph[x][y] << endl;

        total_cost += graph[x][y];

        selected[y] = true;

        edge_count++;
    }

    cout << "\nTotal Minimum Cost = "
         << total_cost << endl;

    return 0;
}