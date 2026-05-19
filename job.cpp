#include <iostream>
#include <algorithm>
using namespace std;

struct Job {

    string id;
    int deadline;
    int profit;
};

// Compare jobs by profit
bool compare(Job a, Job b) {

    return a.profit > b.profit;
}

int main() {

    Job jobs[] = {

        {"J1", 2, 100},
        {"J2", 1, 19},
        {"J3", 2, 27},
        {"J4", 1, 25},
        {"J5", 3, 15}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]);

    // Sort jobs by profit
    sort(jobs, jobs + n, compare);

    // Find maximum deadline
    int maxDeadline = 0;

    for(int i = 0; i < n; i++) {

        if(jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Slots initialization
    string slot[maxDeadline];
    bool filled[maxDeadline];

    for(int i = 0; i < maxDeadline; i++) {

        filled[i] = false;
    }

    int totalProfit = 0;

    // Schedule jobs
    for(int i = 0; i < n; i++) {

        for(int j = jobs[i].deadline - 1;
            j >= 0;
            j--) {

            if(!filled[j]) {

                slot[j] = jobs[i].id;

                filled[j] = true;

                totalProfit += jobs[i].profit;

                break;
            }
        }
    }

    // Print sequence
    cout << "Selected Job Sequence:\n";

    for(int i = 0; i < maxDeadline; i++) {

        if(filled[i])
            cout << slot[i] << " ";
    }

    cout << "\nTotal Profit = "
         << totalProfit;

    return 0;
}