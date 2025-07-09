#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> PII;

void dijkstra(int start, vector<vector<PII>> &graph, int V)
{
    // this would create array with V numbers and init with max numbers of cpp
    vector<int> nodeDistance(V, INT_MAX);
    // a kind of queue which dose not order items base on instert
    // the first type PII we are saying this type what is going to store
    // the second type say how the internall contianer should store inserted items
    // the third type say how to sort the items in
    // by default this sort by MAX_HYPE but we need MIN here
    priority_queue<PII, vector<PII>, greater<PII>> pg;
    // strat from source node
    //  we set the source to 0 to show where we are going to start
    nodeDistance[start] = 0;
    // push it to queue
    pg.push({0, start});
    // proccess the queue
    while (!pg.empty())
    {
        int currentDist = pg.top().first;
        int currentNode = pg.top().second;
        pg.pop();
        for (auto neighbor : graph[currentNode])
        {
            int nextNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if (nodeDistance[nextNode] > currentDist + edgeWeight)
            {
                nodeDistance[nextNode] = currentDist + edgeWeight;
                pg.push({nodeDistance[nextNode], nextNode});
            }
        }
    }
    cout << "Shortest distance from node " << start << ":\n";
    for (int i = 0; i < V; i++)
    {
        cout << "To node " << i << " -> " << nodeDistance[i] << "\n";
    }
}

int main()
{
    int v = 5; // number of nodes
    vector<vector<PII>> graph(v);

    // add edges
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({4, 3});
    graph[3].push_back({4, 1});
}