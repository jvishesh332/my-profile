#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

// Find operation of Union-Find algorithm
int find(int x) {
if (parent[x] == x)
return x;
return parent[x] = find(parent[x]);
}

// Union operation of Union-Find algorithm
void unionSet(int x, int y) {
int parentX = find(x);
int parentY = find(y);
parent[parentX] = parentY;
}

int makeConnected(int n, vector<vector<int>>& connections) {
// If the number of connections is less than n-1, it is not possible to connect all workstations
if (connections.size() < n - 1)
return -1;

parent.resize(n);
for (int i = 0; i < n; i++)
parent[i] = i;

int components = n;

for (auto& connection : connections) {
int workstation1 = connection[0];
int workstation2 = connection[1];

if (find(workstation1) != find(workstation2)) {
unionSet(workstation1, workstation2);
components--;
}
}

// Minimum number of times to connect all workstations is equal to the number of components - 1
return components - 1;
}

int main() {
int n = 4;
vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};

int minConnections = makeConnected(n, connections);

cout << "Minimum number of times to connect all workstations: " << minConnections << endl;

return 0;
}