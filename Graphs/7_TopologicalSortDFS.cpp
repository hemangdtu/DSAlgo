#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph
{
	private:
		map<T, list<T>> l;

	public:
		void addEdge(T x, T y)
		{
			l[x].push_back(y);
		}

		void dfsHelper(T source, map<T, bool>& visited, list<T>& ordering)
		{
			visited[source] = true;
			for(auto neighbour : l[source])
				if(!visited[neighbour])
					dfsHelper(neighbour, visited, ordering);

			ordering.push_front(source);
		}

		void dfs()
		{
			map<T, bool> visited;
			list<T> ordering;

			for(auto value : l)
			{
				T node = value.first;
				visited[node] = false;
			}

			for(auto value : l)
			{
				T node = value.first;
				if(!visited[node])
					dfsHelper(node, visited, ordering);
			}

			// Simply print the ordering node here.
			for(auto node : ordering)
				cout << node << "\n";
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