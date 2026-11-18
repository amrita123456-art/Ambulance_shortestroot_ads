
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <algorithm>
using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    vector<string> places = {
        "Ambulance Station",
        "Main Junction",
        "Railway Crossing",
        "City Centre",
        "Market Area",
        "University",
        "City Hospital"
    };

    int n = places.size();

    // Adjacency list: neighbour and road distance
    vector<vector<pair<int, int>>> graph(n);

    auto addRoad = [&](int u, int v, int w) {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    };

    addRoad(0, 1, 4);
    addRoad(0, 2, 2);
    addRoad(1, 2, 1);
    addRoad(1, 3, 5);
    addRoad(2, 3, 8);
    addRoad(2, 4, 10);
    addRoad(3, 4, 2);
    addRoad(3, 5, 6);
    addRoad(4, 5, 3);
    addRoad(4, 6, 7);
    addRoad(5, 6, 2);

    cout << "\nAMBULANCE ROUTE OPTIMIZATION\n";
    cout << "Using Dijkstra's Algorithm\n\n";

    for (int i = 0; i < n; i++)
        cout << i + 1 << ". " << places[i] << endl;

    int source, destination;

    cout << "\nEnter starting location number: ";
    cin >> source;

    cout << "Enter destination number: ";
    cin >> destination;

    if (source < 1 || source > n ||
        destination < 1 || destination > n) {
        cout << "Invalid location!";
        return 0;
    }

    source--;
    destination--;

    vector<int> dist(n, INF), parent(n, -1);

    priority_queue<pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d != dist[u]) continue;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[destination] == INF) {
        cout << "No route available.";
        return 0;
    }

    vector<int> path;

    for (int v = destination; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "\nShortest Route:\n";

    for (int i = 0; i < path.size(); i++) {
        cout << places[path[i]];
        if (i != path.size() - 1)
            cout << " -> ";
    }

    cout << "\nTotal Distance: "
         << dist[destination] << " km\n";

    return 0;
    