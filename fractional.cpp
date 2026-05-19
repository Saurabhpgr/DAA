#include <iostream>
#include <algorithm>
using namespace std;

struct Item {

    int profit;
    int weight;
};

bool compare(Item a, Item b) {

    double r1 =
    (double)a.profit / a.weight;

    double r2 =
    (double)b.profit / b.weight;

    return r1 > r2;
}

int main() {

    Item items[] = {

        {60, 10},
        {100, 20},
        {120, 30}
    };

    int n = 3;

    int capacity = 50;

    // Sort according to ratio
    sort(items, items + n, compare);

    double totalProfit = 0.0;

    cout << "Selected Items:\n";

    for(int i = 0; i < n; i++) {

        if(capacity >= items[i].weight) {

            // Take complete item
            capacity -= items[i].weight;

            totalProfit += items[i].profit;

            cout << "Full item taken "
                 << "(Profit = "
                 << items[i].profit
                 << ", Weight = "
                 << items[i].weight
                 << ")\n";
        }

        else {

            // Take fractional part
            double fraction =
            (double)capacity /
            items[i].weight;

            totalProfit +=
            items[i].profit * fraction;

            cout << "Fraction "
                 << fraction
                 << " of item taken\n";

            capacity = 0;

            break;
        }
    }

    cout << "\nMaximum Profit = "
         << totalProfit;

    return 0;
}