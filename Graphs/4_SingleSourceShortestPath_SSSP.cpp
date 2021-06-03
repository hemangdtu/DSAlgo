// For Unweighted Graph

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

		void sssp(T source)
		{
			map<T, int> distance;
			queue<T> q;

			for(auto i : l)
			{
				T node = i.first;
				distance[node] = INT_MAX;
			}
			q.push(source);
			distance[source] = 0;

			while(!q.empty())
			{
				T node = q.front();
				q.pop();

				for(auto i : l[node])
				{
					if(distance[i] == INT_MAX)
					{
						q.push(i);
						distance[i] = distance[node] + 1;
					}
				}
			}

			for(auto node_pair : l)
				cout << "NODE: " << node_pair.first << " DISTANCE: " << distance[node_pair.first] << "\n";
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

	g.sssp(0);

	return 0;
}