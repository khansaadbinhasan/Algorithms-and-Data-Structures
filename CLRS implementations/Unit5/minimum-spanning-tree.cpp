#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>

using namespace std; 

vector< pair<int, int> > adj[100];
int V = 5;


void addEdge(int u, int v, int wt); 
void printGraph(); 
set<string> MST_kruskal();
void MST_prim();


int main() 
{ 
	addEdge( 0, 1, 10); 
	addEdge( 0, 4, 20); 
	addEdge( 1, 2, 30); 
	addEdge( 1, 3, 40); 
	addEdge( 1, 4, 50); 
	addEdge( 2, 3, 60); 
	addEdge( 3, 4, 70); 

	cout << "The graph obtained is:" << endl;
	printGraph();
	
	set<string> A = MST_kruskal();

	cout << "{ ";

	for (set<string>::iterator i = A.begin(); i != A.end(); ++i)
	{
		cout << "(" << *i << ")" << " , ";
	}

	cout << " }";

	cout << endl;

	return 0; 
} 




void addEdge(int u, int v, int wt) 
{ 
	adj[u].push_back(make_pair(v, wt)); 
	adj[v].push_back(make_pair(u, wt)); 
} 

void printGraph() 
{ 
	int v, w; 

	for (int u = 0; u < V; u++) 
	{ 
		cout << u; 
		
		for (auto it = adj[u].begin(); it!=adj[u].end(); it++) 
			cout << " -> " << "(" << it->first << "," << it->second << ")"; 

		cout << endl; 
	}

	cout << endl << endl; 
} 

set<string> MST_kruskal()
{
	map<string, int> NodesToweight;

	//sorting according to edge weights
	for (int i = 0; i < V; ++i)
	{
		ostringstream node1;
		node1 << i;

		for (vector< pair<int,int> >::iterator v = adj[i].begin(); v != adj[i].end(); ++v)
		{
			ostringstream node2;
			node2 << v->first;

			string nodePair = node1.str() + "," + node2.str();			

			NodesToweight.insert( pair< string, int > (nodePair, v->second) );
		}
	}


	vector< pair<string, int> > newNodeMap;

	while( !NodesToweight.empty() )
	{
		string kay;
		int min = 1000;

		for( map<string, int>::iterator m = NodesToweight.begin(); m != NodesToweight.end(); m++ )
		{
			if( m->second < min )
			{
				kay = m->first;
				min = m->second;
			}
		}

		newNodeMap.push_back( pair< string, int > ( kay, min ) );
		NodesToweight.erase(kay);


		// cout << kay << "\t" << min << endl;
	}



	set<string> A;

	vector< set<int> > nodeSetVector;

	for(int v = 0; v < V; v++)
	{
		set<int> temp({v});
		nodeSetVector.push_back(temp);
	}



	for ( vector< pair<string, int> >::iterator i = newNodeMap.begin(); i != newNodeMap.end(); ++i )
	{
		string k = i->first;

		char u = k[0];
		char v = k[2];

		int uInt = u - '0';
		int vInt = v - '0';

		set<int> *setU;
		set<int> *setV;

		int flag = 0;

		for(int i = 0; i < nodeSetVector.size(); ++i)
		{
			if( nodeSetVector[i].find(uInt) != nodeSetVector[i].end() )
				setU = &nodeSetVector[i];

			if( nodeSetVector[i].find(vInt) != nodeSetVector[i].end() )
				setV = &nodeSetVector[i];

			if( nodeSetVector[i].find(uInt) != nodeSetVector[i].end() and  nodeSetVector[i].find(vInt) != nodeSetVector[i].end() )
				flag = 1;
		}

		if( flag == 0 )
		{
			string str1(1,u);
			string str2(1,v);

			A.insert(str1+","+str2);
			// A = A U {(u,v)};
			(*setU).insert((*setV).begin(), (*setV).end());
			// UNION(u,v);
		}
	}

	return A;
}



