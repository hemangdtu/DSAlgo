#include<bits/stdc++.h>
using namespace std;

class Graph
{
	private:
		unordered_map<string, list<pair<string, int>>> l;

	public:
		void addEdge(string source, string destination, bool bidirection, int weight)
		{
			l[source].push_back(make_pair(destination, weight));
			if(bidirection)
				l[destination].push_back(make_pair(source, weight));
		}

		void printGraph()
		{
			for(auto p : l)
			{
				string city = p.first;
				list<pair<string, int>> neighbours = p.second;

				cout << city << " -> ";
				for(auto i : neighbours)
				{
					string dest = i.first;
					int distance = i.second;
					cout << dest << ", " << distance << " ";
				}
				cout<<"\n";
			}
		}
};

int main()
{
	Graph g;
	g.addEdge("A", "B", true, 20);
	g.addEdge("B", "D", true, 40);
	g.addEdge("A", "C", true, 10);
	g.addEdge("C", "D", true, 40);
	g.addEdge("A", "D", false, 50);
	
	g.printGraph();
	return 0;
}