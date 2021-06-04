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
			l[y].push_back(x);
		}

		bool isTree()
		{
			// This basically detects a cycle in an Undirected Graph.
			bool* visited = new bool[V];
			int *parent =  new int[V];
			queue<int> q;

			for(int i = 0; i<V; i++)
			{
				visited[i] = false;
				parent[i] = i;
			}

			int source = 0;
			q.push(source);
			visited[source] = true;

			while(!q.empty())
			{
				int node = q.front();
				q.pop();
				for(int neighbour : l[node])
				{
					if(visited[neighbour] && parent[node] != neighbour)
						return false;
					else if(!visited[neighbour])
					{
						visited[neighbour] = true;
						parent[neighbour] = node;
						q.push(neighbour);
					}
				}
			}

			return true;
		}
};

int main()
{
	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(3, 2);
	g.addEdge(1, 2);
	g.addEdge(0, 3);

	if(g.isTree())
		cout << "Yes, it is a Tree.";
	else
		cout << "No, it's not a Tree.";

	return 0;
}