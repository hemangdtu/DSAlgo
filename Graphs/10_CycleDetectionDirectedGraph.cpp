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

		void addEdge(int x, int y, bool directed = true)
		{
			l[x].push_back(y);
			
			if(!directed)
				l[y].push_back(x);
		}

		bool cycleHelperFunc(int node, bool* visited, bool* stack)
		{
			// Visiting a node
			visited[node] = true;
			stack[node] = true;

			for(int neighbour : l[node])
			{
				if(stack[neighbour]) // == true
					return true;
				else if(!visited[neighbour]) // != false
				{
					bool cyclePresentConfirmation = cycleHelperFunc(neighbour, visited, stack);
					if(cyclePresentConfirmation)
						return true;
				}
			}

			// Leaving a node
			stack[node] = false;
			return false;
		}

		bool cycleExists()
		{
			bool *visited = new bool[V];
			bool *stack = new bool[V];

			for(int i = 0; i<V; i++)
				visited[i] = stack[i] = false;

			return cycleHelperFunc(0, visited, stack);
		}
};

int main()
{
	Graph g(7);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(1, 5);
	g.addEdge(5, 6);
	g.addEdge(4, 2);	// Back Edge

	if(g.cycleExists())
		cout << "Yes, cycle exists.";
	else
		cout << "No, cycle doesn't exist.";

	return 0;
}