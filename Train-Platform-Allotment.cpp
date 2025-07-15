#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Train {
    int arrival;
    int departure;
    int id;
};

bool compare(Train a, Train b) {
    return a.arrival < b.arrival;
}

int main() {
    int n;
    cout << "Enter number of trains: ";
    cin >> n;

    vector<Train> trains(n);
    for (int i = 0; i < n; ++i) {
        cout << "Train " << i+1 << " (Arrival Departure): ";
        cin >> trains[i].arrival >> trains[i].departure;
        trains[i].id = i + 1;
    }

    sort(trains.begin(), trains.end(), compare);

    // priority_queue< {departure time, platform number} >
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    vector<int> assigned(n);  // platform assigned to each train
    int platformCount = 0;

    for (int i = 0; i < n; ++i) {
        int arr = trains[i].arrival;
        int dep = trains[i].departure;

        if (!pq.empty() && pq.top().first <= arr) {
            // Reuse existing platform
            int plat = pq.top().second;
            pq.pop();
            assigned[trains[i].id - 1] = plat;
            pq.push({dep, plat});
        } else {
            // New platform
            platformCount++;
            assigned[trains[i].id - 1] = platformCount;
            pq.push({dep, platformCount});
        }
    }

    // Output results
    cout << "\nPlatform Assignments:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Train " << i+1 << " -> Platform " << assigned[i] << "\n";
    }

    cout << "\nTotal Platforms Used: " << platformCount << "\n";

    return 0;
}
