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

		void dfs()
		{
			map<T, bool> visited;

			for(auto value : l)
			{
				T node = value.first;
				visited[node] = false;
			}

			int count = 0;

			for(auto value : l)
			{
				T node = value.first;
				if(!visited[node])
				{
					cout << "Component " << count << " -> ";
					dfsHelper(node, visited);
					count++;
					cout << "\n";
				}
			}
		}
};

int main()
{
	Graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(0, 3);
	g.addEdge(0, 4);

	g.addEdge(5, 6);
	g.addEdge(6, 7);

	g.addEdge(8, 8);

	g.dfs();

	return 0;
}