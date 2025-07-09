### Breadth-First Search (BFS) Algorithm Explanation
This document explains the Breadth-First Search (BFS) algorithm as implemented in the provided C++ code. BFS is a fundamental graph traversal algorithm used to find the shortest path from a start node to a target node in an unweighted graph.

Let's break down how this algorithm works step by step:

### Algorithm Overview
BFS explores a graph level by level. It starts at the source node and explores all its immediate neighbors. Then, for each of those neighbors, it explores their unvisited neighbors, and so on. This ensures that the shortest path (in terms of the number of edges) is found first in an unweighted graph.

#### Step-by-Step Breakdown of the Code

## 1. Initialization
``` c
 queue<string> q;
 unordered_map<string, bool> visited;
 unordered_map<string, string> parent;  // For tracking path
    q.push(start);
    visited[start] = true;

```
* **`queue<string> q;`**: A queue is the core data structure for BFS. It stores the nodes to be visited in a First-In, First-Out (FIFO) manner. This ensures that nodes are explored level by level.

* **`unordered_map<string, bool> visited;`**: This map keeps track of which nodes have already been visited. This prevents cycles and ensures that each node is processed only once, which is crucial for efficiency and correctness.

* **`unordered_map<string, string> parent;`**: This map is used to reconstruct the path from the `start` node to the `target` node once the target is found. When a node `neighbor` is visited for the first time, its `parent` is set to the `current` node from which it was discovered.

* **`q.push(start);`**: The `start` node is added to the queue to begin the traversal.

* **`visited[start] = true;`**: The `start` node is marked as visited immediately.

## 2. Main BFS Loop
``` c
    while (!q.empty()) {
        string current = q.front();
        q.pop();

        cout << "Visiting: " << current << endl;
        // ... rest of the loop
    }
```
The `while (!q.empty())` loop continues as long as there are nodes in the queue to visit.

* **`string current = q.front();`**: The node at the front of the queue is retrieved. This is the node currently being processed.

* **`q.pop();`**: The `current` node is removed from the queue.

* **`cout << "Visiting: " << current << endl;`**: This line provides feedback, showing which node is currently being explored.

## 3. Target Check
```c
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


```
* **`if (current == target)`**: If the `current` node being processed is the `target` node, the algorithm has found the shortest path.

* **Path Reconstruction**:

  * A `vector<string> path;` is used to store the path.

  * The `while (current != start)` loop traces back from the `target` node to the `start` node using the `parent` map. Each `current` node is added to the `path` vector, and then `current` is updated to its parent.

  * After the loop, the `start` node is also added to the `path`.

  * The path is then printed in reverse order (from `start` to `target`) to show the correct sequence.

* **`return;`**: Once the target is found and the path is printed, the function terminates.

## 4. Explore Neighbors
```c
        for (string neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
```
* **`for (string neighbor : graph[current])`**: This loop iterates through all the direct neighbors of the `current` node. It assumes `graph` is an adjacency list (e.g., `unordered_map<string, vector<string>>`) that stores the connections between nodes.

* **`if (!visited[neighbor])`**: For each `neighbor`, the algorithm checks if it has already been visited.

* **If not visited**:

  * **`visited[neighbor] = true;`**: The `neighbor` is marked as visited.

  * **`parent[neighbor] = current;`**: The `current` node is recorded as the parent of the `neighbor`. This is crucial for path reconstruction.

  * **`q.push(neighbor);`**: The `neighbor` is added to the queue to be processed later.

## 5. Target Not Found
```c
    cout << "Target not found!" << endl;
```
If the `while (!q.empty())` loop finishes and the `target` node was never found (i.e., the `return` statement inside the `if (current == target)` block was never executed), it means the `target` node is not reachable from the `start` node. In this case, a "Target not found!" message is printed.

## Summary

This BFS implementation correctly uses a queue for level-order traversal, a `visited` map to prevent redundant processing and cycles, and a `parent` map to reconstruct the shortest path. It's a solid and standard approach for solving shortest path problems in unweighted graphs.