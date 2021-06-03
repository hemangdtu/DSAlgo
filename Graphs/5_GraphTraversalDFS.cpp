#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph
{
	private:
		map<T, list<T>> l;

	public:
		void addEdge(int x, int y)
		{
			l[x].push_back(y);
			l[y].push_back(x);
		}

		void dfsHelper(T source, map<T, bool>& visited)
		{
			cout << source << " ";
			visited[source] = true;
			for(auto neighbour : l[source])
				if(!visited[neighbour])
					dfsHelper(neighbour, visited);
		}

		void dfs(T source)
		{
			map<T, bool> visited;

			for(auto value : l)
			{
				T node = value.first;
				visited[node] = false;
			}

			dfsHelper(source, visited);
		}
};

int main()
{
	Graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(4, 3);
	g.addEdge(4, 5);

	g.dfs(0);

	return 0;
}