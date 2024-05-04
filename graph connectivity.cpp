#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

void dfs(const char node, const map<char, set<char>>& graph, set<char>& visited) {
    visited.insert(node);
    for (char neighbor : graph.at(node)) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, graph, visited);
        }
    }
}
int countMaximalConnectedSubgraphs(map<char, set<char>>& graph) {
    set<char> visited;
    int count = 0;
    for (const auto& pair : graph) {
        char node = pair.first;
        if (visited.find(node) == visited.end()) {
            dfs(node, graph, visited);
            count++;
        }
    }

    return count;
}
int main() {
    int num_cases;
    cin >> num_cases;
    string line;
    getline(cin, line);
    bool first_case = true;
    while (num_cases--) {
        if (!first_case) {
            cout << endl;
        }
        first_case = false;
        getline(cin, line);
        char largest_node = line[0];
        map<char, set<char>> graph;
        while (getline(cin, line) && !line.empty()) {
            char u = line[0];
            char v = line[1];
            graph[u].insert(v);
            graph[v].insert(u);
        }
        int num_maximal_subgraphs = countMaximalConnectedSubgraphs(graph);
        cout << num_maximal_subgraphs;
        graph.clear();
    }

    return 0;
}

