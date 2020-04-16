#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int n = 7;

vi dske_G[100];

int visited[100];

void dfs(int u)
{
	if(visited[u] == 1)
		return;

	visited[u] = 1;

	cout << u << ", ";

	for(auto i : dske_G[u])
		dfs(i);
}

void bfs(int u)
{
	queue<int> q;
	q.push(u);

    visited[u] = 1;

	while(!q.empty()) {
		int s = q.front();
		q.pop();

		cout << s << ", ";

		for(auto i : dske_G[s]) {
			if(visited[i] == 0) {
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}

bool check_connectivity()
{
	dfs(1);
	for (int i = 1; i <= n; ++i) {
		/* code */
		if(visited[i] == 0) {
			cout << "Not connected" << "\n";
			return false;
		}
	}

	cout << "connected" << "\n";
	return true;
}

void find_all_connected_component()
{
	for(int i = 1; i <= n; ++i) {
		if(visited[i] == 0) {
			cout << "\nnew component: " << "\n";
			dfs(i);
		}
	}
}

int main(int argc, char const *argv[])
{
	dske_G[1].push_back(2);
	dske_G[1].push_back(4);
	dske_G[2].push_back(1);
	dske_G[2].push_back(3);
	dske_G[2].push_back(5);
	dske_G[3].push_back(2);
	dske_G[3].push_back(5);
	dske_G[5].push_back(2);
	dske_G[5].push_back(3);

	dske_G[6].push_back(7);
	dske_G[7].push_back(6);

	// bfs(1);
	// dfs(1);

	// check_connectivity();

	find_all_connected_component();

	return 0;
}









