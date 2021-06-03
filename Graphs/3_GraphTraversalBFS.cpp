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

		void bfs(T source)
		{
			map<T, bool> visited;
			queue<T> q;

			q.push(source);
			visited[source] = true;

			while(!q.empty())
			{
				T node = q.front();
				q.pop();

				cout << node << " ";

				for(auto i : l[node])
				{
					if(!visited[i])
					{
						q.push(i);
						visited[i] = true;
					}
				}
			}
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

	g.bfs(0);

	return 0;
}