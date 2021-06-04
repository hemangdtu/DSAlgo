#include<bits/stdc++.h>
using namespace std;

class Graph
{
	private:
		list<int>* l;
		int V;

	public:
		Graph(int V)
		{
			this -> V = V;
			l = new list<int> [V];
		}

		void addEdge(int x, int y)
		{
			l[x].push_back(y);
		}

		void topologicalSort()
		{
			int* indegree = new int[V];

			for(int i = 0; i<V; i++)
				indegree[i] = 0;

			for(int p = 0; p<V; p++)
				for(int y : l[p])
					indegree[y]++;

			queue<int> q;

			for(int i = 0; i<V; i++)
				if(indegree[i] == 0)
					q.push(i);

			while(!q.empty())
			{
				int node = q.front();
				cout << node << " ";
				q.pop();
				for(int p : l[node])
				{
					indegree[p]--;
					if(indegree[p] == 0)
						q.push(p);
				}
			}
		}
};

int main()
{
	Graph g(6);

	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(4, 5);
	g.addEdge(2, 5);
	g.addEdge(2, 3);
	g.addEdge(3, 5);

	g.topologicalSort();

	return 0;
}