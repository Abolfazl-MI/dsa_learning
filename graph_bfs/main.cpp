#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// Graph represented as adjacency list
unordered_map<string, vector<string>> graph;

// BFS Function
void bfs(string start, string target) {
    queue<string> q;
    unordered_map<string, bool> visited;
    unordered_map<string, string> parent;  // For tracking path

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        cout << "Visiting: " << current << endl;

        if (current == target) {
            // Found target, reconstruct path
            cout << "Found target: " << target << endl;

            vector<string> path;
            while (current != start) {
                path.push_back(current);
                current = parent[current];
            }
            path.push_back(start);

            cout << "Shortest Path: ";
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << path[i];
                if (i > 0) cout << " -> ";
            }
            cout << endl;
            return;
        }

        for (string neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    cout << "Target not found!" << endl;
}

int main() {
    // Building a sample social network graph
    graph["A"] = {"B", "C"};
    graph["B"] = {"A", "D"};
    graph["C"] = {"A", "D"};
    graph["D"] = {"B", "C", "E"};
    graph["E"] = {"D"};

    string start = "A";
    string target = "E";

    bfs(start, target);

    return 0;
}
