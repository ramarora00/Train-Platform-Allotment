#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Train {
    int arrival;
    int departure;
    int id;
};

bool compare(Train a, Train b) {
    return a.arrival < b.arrival;
}

bool isValidTime(int time) {
    if (time < 0 || time > 2359) return false;
    int hours = time / 100;
    int minutes = time % 100;
    return (hours >= 0 && hours <= 23 && minutes >= 0 && minutes < 60);
}

int main() {
    int n;
    cout << "Enter number of trains: ";
    cin >> n;

    if (n <= 0) {
        cout << "No trains to schedule. Exiting...\n";
        return 0;
    }

    vector<Train> trains(n);
    for (int i = 0; i < n; ++i) {
        int arr, dep;

        cout << "\nEnter timings for Train " << i + 1 << ":\n";

        while (true) {
            cout << "  Arrival Time (HHMM): ";
            cin >> arr;
            if (isValidTime(arr)) break;
            cout << "  Invalid time. Please enter in HHMM format (0000 to 2359).\n";
        }

        while (true) {
            cout << "  Departure Time (HHMM): ";
            cin >> dep;
            if (isValidTime(dep) && dep >= arr) break;
            cout << "  Invalid or earlier than arrival. Try again.\n";
        }

        trains[i].arrival = arr;
        trains[i].departure = dep;
        trains[i].id = i + 1;
    }

    sort(trains.begin(), trains.end(), compare);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> assigned(n);
    int platformCount = 0;

    for (int i = 0; i < n; ++i) {
        int arr = trains[i].arrival;
        int dep = trains[i].departure;

        if (!pq.empty() && pq.top().first <= arr) {
            int plat = pq.top().second;
            pq.pop();
            assigned[trains[i].id - 1] = plat;
            pq.push({dep, plat});
        } else {
            platformCount++;
            assigned[trains[i].id - 1] = platformCount;
            pq.push({dep, platformCount});
        }
    }

    cout << "\nPlatform Assignments:\n";
    for (int i = 0; i < n; ++i) {
        printf("  Train %d [%04d - %04d] → Platform %d\n",
               trains[i].id, trains[i].arrival, trains[i].departure, assigned[i]);
    }

    cout << "\nTotal Platforms Used: " << platformCount << "\n";

    return 0;
}
