#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std; 

class Vertex
{
public:
	int ID;
	string color;
	int dist;
	Vertex *parent;

	Vertex(int ID)
	{
		this->ID = ID;
		this->color = "WHITE";
		this->dist = 100000;
		this->parent = NULL;
	}
};



void addEdge(Vertex* u, Vertex* v);
void printGraph();
void BFS(Vertex *s);
void print_path_BFS(Vertex *s, Vertex *v);

int numVert = 5; 
vector<Vertex*> adj[100];
vector<Vertex*> vertices;

int main() 
{ 
	for (int id = 0; id < numVert; ++id)
	{
		Vertex* vert = new Vertex(id);
		vertices.push_back(vert);
	}

	cout << endl;


	/*
	undirected graph
	     

	     _____________
		|			  |
		|			  |
		0--------1----4
				/ \   |
			   /   \  |
			  /	    \ |
		     /       \|
			2---------3				    


	*/
	addEdge(vertices[0], vertices[1]); 
	addEdge(vertices[0], vertices[4]); 
	addEdge(vertices[1], vertices[2]); 
	addEdge(vertices[1], vertices[3]); 
	addEdge(vertices[1], vertices[4]); 
	addEdge(vertices[2], vertices[3]); 
	addEdge(vertices[3], vertices[4]); 
	
	printGraph(); 

	BFS(vertices[0]);
	print_path_BFS(vertices[0],vertices[3]);

	cout << endl;

	return 0; 
} 


void addEdge(Vertex* u, Vertex* v)
{ 
	adj[u->ID].push_back(v); 
	adj[v->ID].push_back(u); 
} 

void printGraph()
{ 
	cout << endl << endl;

	for ( int i = 0; i < vertices.size(); i++ ) 
	{ 
		cout << "\n Adjacency list of vertex " << vertices[i]->ID << "\n head "; 
		
		for(int j = 0; j < adj[vertices[i]->ID].size(); j++) 
			cout << "-> " << adj[vertices[i]->ID][j]->ID; 
		
		printf("\n");
	}

	cout << endl << endl << endl; 
} 


void BFS(Vertex *s)
{
	queue<Vertex*> Q;

	s->color = "GRAY";
	s->dist = 0;

	Q.push(s);

	while(!Q.empty())
	{
		Vertex *u = Q.front();
		Q.pop();

		for( int i = 0; i < adj[u->ID].size(); i++ )
		{
			if( adj[u->ID][i]->color == "WHITE" )
			{
				adj[u->ID][i]->color = "GRAY";
				adj[u->ID][i]->dist = u->dist + 1;
				adj[u->ID][i]->parent = u;

				Q.push(adj[u->ID][i]);

				// cout << adj[u->ID][i]->ID << endl;
			}
		}

		u->color = "BLACK";
	}	


}


void print_path_BFS(Vertex *s, Vertex *v)
{
	if( v->ID == s->ID )
		cout << s->ID << "\t";

	else if( v->parent == NULL )
		cout << "No path exists" << endl;

	else
	{
		print_path_BFS(s, v->parent);
		cout << v->ID << "\t";
	}
}


void initialize_single_source()
{
	for v e vertices
	{
		v->dist = 100000;
		v->parent = NULL;
	}

	s->dist = 0;
}

void relax()
{
	if( v->dist > u->dist + w(u,v) )
	{
		v->dist = u->dist + w(u,v);
		v->parent = u;
	}
}

bool bellman_ford()
{
	initialize_single_source();

	for( i = 1 to |V[G]| - 1)
	{
		for( (u,v) e E[G] )
			relax()
	}

	for( (u,v) e E[G] )
	{
		if( v->dist > u->dist + w(u,v) )
			return false;
	}

	return true;
}


void dag_shortest_paths()
{
	topologically sort vertices of G

	initialize_single_source();

	for( u taken in order )
	{
		for( v e adj[u] )
		{
			relax();
		}
	}
}


void dijkstra()
{
	initialize_single_source();

	S = phi;
	Q = vertices;

	while( !Q.isempty() )
	{
		u = Q.extract_min();
		S = S U {u};

		for( v e adj[u] )
			relax();
	}
}