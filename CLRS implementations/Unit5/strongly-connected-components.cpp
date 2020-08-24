#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std; 

class Vertex
{
public:
	int ID;
	string color;
	int discTime;
	int finish;
	Vertex *parent;

	Vertex(int ID)
	{
		this->ID = ID;
		this->color = "WHITE";
		this->discTime= -1;
		this->finish = -1;
		this->parent = NULL;
	}
};



void printGraph(vector<Vertex*> a[]);
void DFS_visit(Vertex* u, vector<Vertex*> a[]);
void transpose_graph();

int numVert = 8; 
int Time = 0;
vector<Vertex*> adj[100];
vector<Vertex*> transAdj[100];
vector<Vertex*> vertices;
vector<Vertex*> transVertices;



bool compareVertices(Vertex* v1, Vertex* v2)
{
	return (v1->finish < v2->finish);
}

int main() 
{ 
	for (int id = 0; id < numVert; ++id)
	{
		Vertex* vert = new Vertex(id);
		vertices.push_back(vert);
	}


	adj[0].push_back(vertices[1]); 
	adj[1].push_back(vertices[2]); adj[1].push_back(vertices[3]); adj[1].push_back(vertices[5]); 
	adj[2].push_back(vertices[4]); adj[2].push_back(vertices[7]); 
	adj[3].push_back(vertices[4]);
	adj[4].push_back(vertices[3]); adj[4].push_back(vertices[6]);
	adj[5].push_back(vertices[0]); adj[5].push_back(vertices[3]); 
	adj[6].push_back(vertices[6]); 
	adj[7].push_back(vertices[2]); adj[7].push_back(vertices[6]); 

	printGraph(adj); 


	for (int i = 0; i < vertices.size(); ++i)
	{
		if( vertices[i]->color == "WHITE" )
			DFS_visit(vertices[i], adj);
	}


	transpose_graph();

	printGraph(transAdj); 


	int n = sizeof(vertices)/sizeof(vertices[0]);

	sort(vertices.begin(), vertices.end(), compareVertices);


	std::sort(vertices.begin(), vertices.end(), 
												[](Vertex* v1, Vertex* v2)
												{
													return v1->finish > v2->finish;
												});


	for (int i = 0; i < vertices.size(); ++i)
		vertices[i]->color = "WHITE";


	for (int i = 0; i < vertices.size(); ++i)
	{
		if( vertices[i]->color == "WHITE" )
		{
			DFS_visit(vertices[i], transAdj);
			cout << endl;
		}
	}

	cout << endl;

	return 0; 
} 



void printGraph(vector<Vertex*> a[])
{ 
	cout << endl << endl;

	for ( int i = 0; i < vertices.size(); i++ ) 
	{ 
		cout << "\n Adjacency list of vertex " << vertices[i]->ID << "\n head "; 
		
		for(int j = 0; j < a[vertices[i]->ID].size(); j++) 
			cout << "-> " << a[vertices[i]->ID][j]->ID; 
		
		printf("\n");
	}

	cout << endl << endl << endl; 
} 

void DFS_visit(Vertex* u, vector<Vertex*> a[])
{
	u->color = "GRAY";
	Time = Time + 1;
	u->discTime = Time;

	for(int j = 0; j < a[u->ID].size(); j++) 
	{
		if( a[u->ID][j]->color == "WHITE" )
		{
			a[u->ID][j]->parent = u;
			DFS_visit(a[u->ID][j],a);
		}	
	}

	u->color = "BLACK";
	u->finish = Time = Time + 1;

	cout << u->ID << "\t";
}

void transpose_graph()
{
	for ( int i = 0; i < vertices.size(); i++ ) 
	{ 
		for(int j = 0; j < adj[vertices[i]->ID].size(); j++) 
		{
			int index = adj[vertices[i]->ID][j]->ID;
			int flag = 1;

			for( int k = 0; k < transAdj[index].size(); k++ )
			{
				if( transAdj[index][k]->ID == adj[vertices[i]->ID][j]->ID  )
				{
					flag = 0;
					break;
				}
			}

			if( flag == 1 )
				transAdj[index].push_back(vertices[i]);
		}
	}	
}