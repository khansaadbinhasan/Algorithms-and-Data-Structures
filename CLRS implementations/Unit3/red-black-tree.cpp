#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	int key;
	Node* left;
	Node* right;
	Node* parent;
	string color;


	Node()
	{
		this->key = -1000;
		this->color = "BLACK";		
	}

};

Node* root = new Node();
Node* nil = new Node();


void Noddy(Node* node)
{
	node->left = nil;
	node->right = nil;
	node->parent = nil;
}



Node* tree_minimum( Node* x );
Node* tree_successor( Node* x );
void left_rotate( Node* x );
void right_rotate( Node* x );
void RBinsert( Node* z );
void RB_insert_fixup( Node* z );
Node* RBdelete( Node* z );
void RBdelete_fixup( Node* x );
void inorder_tree_walk( Node* x );
void print_tree( Node* x );
void demo();


int main()
{
	demo();	
}

void demo()
{
	Noddy(root);
	root = nil;


	int numNodes;
	
	cout << "Enter number of Nodes: ";
	cin >> numNodes;

	Node* z[numNodes];


	for (int i = 0; i < numNodes; ++i)
	{
		z[i] = new Node();

		Noddy(z[i]);

		int key;

		cout << "Enter key: ";
		cin >> key;
		
		z[i]->key = key;

		RBinsert(z[i]);
		
	}

	cout << "after insertion: " << endl;
	print_tree(root);

	Node* temp = new Node();
	temp = tree_successor( root );
	cout << "Successor for: " << root->key << endl << "is: " << temp->key << endl;

	RBinsert( root );
	cout << "after insertion: " << endl;
	print_tree( root );

	// RBdelete(z3);
	// cout << "after deletion: " << endl;
	// print_tree(z2);

}

Node* tree_minimum( Node* x )
{
	while( x->left != NULL )
		x = x->left;

	return x;
}

Node* tree_successor( Node* x )
{
	Node* y = new Node();
	Noddy(y);

	if( x->right != NULL )
		return tree_minimum(x->right);

	y = x->parent;

	while( y->right == x && y != NULL )
	{
		x = y;
		y = y->parent;
	}

	return y;
}

void left_rotate( Node* x )
{
	Node* y = new Node();
	Noddy(y);

	y = x->right;
	x->right = y->left;
	y->left->parent = x;
	y->parent = x->parent;

	if( x->parent == NULL )
		y = root;

	if( x->parent->left == x )
		x->parent->left = y;
	else
		x->parent->right = y;

	x->parent = y;
	y->left = x;
}

void right_rotate( Node* x )
{
	Node* y = new Node();

	Noddy(y);

	y = x->parent;
	x->right->parent = y;
	y->left = x->right;

	if( y->parent == NULL )
		x = root;

	if( y->parent->left == y )
		y->parent->left = x;
	else
		y->parent->right = x;

	y->parent = x;
	x->left = y;
}

void RBinsert( Node* z )
{
	Node* x = new Node();
	Node* y = new Node();

	Noddy(x);
	Noddy(y);

	x = root;
	y = nil;

	while( x != nil )
	{
		// cout << x->key << endl;

		y = x;

		if( z->key < x->key )
			x = x->left;

		else 
			x = x->right;
	}

	z->parent = y;

	if( y == nil )
		root = z; 

	else if( z->key < y->key )
		y->left = z;

	else
		y->right = z;

	z->left = nil;
	z->right = nil;
	z->color = "RED";

	RB_insert_fixup(z);
}	

void RB_insert_fixup( Node* z )
{
	Node* y = new Node();
	Noddy(y);

	while( (z->parent)->color == "RED")
	{
		if( z->parent == z->parent->parent->left )
		{
			y = z->parent->parent->right;

			if( y->color == "RED")
			{
				(z->parent)->color = "BLACK";
				y->color = "BLACK";
				(z->parent->parent)->color = "RED";
				z = z->parent->parent;
			}

			else if( z == z->parent->right )
			{
				z = z->parent;
				left_rotate(z);
			}

			(z->parent)->color = "BLACK";
			(z->parent->parent)->color = "RED";
			right_rotate(z->parent->parent );
		}

		else if( z->parent == z->parent->parent->right )
		{
			y = z->parent->parent->left;

			if( y->color == "RED" )
			{
				(z->parent)->color = "BLACK";
				y->color = "BLACK";
				(z->parent->parent)->color = "RED";
				z = z->parent->parent;
			}

			else if( z == z->parent->left )
			{
				z = z->parent;
				right_rotate(z);
			}

			(z->parent)->color = "BLACK";
			(z->parent->parent)->color = "RED";
			left_rotate(z->parent->parent);
		}
	}

	(root)->color = "BLACK";
}

Node* RBdelete( Node* z )
{
	Node* x = new Node();
	Node* y = new Node();

	Noddy(x);
	Noddy(y);

	if( z->left == nil || z->right == nil )
		y = z;
	else
		y = tree_successor(z);


	if( y->left != nil )
		x = y->left;
	else
		x = y->right;

	x->parent = y->parent;

	if( y->parent == nil )
		root = x;
	else if( y == y->parent->left )
		y->parent->left = x;
	else
		y->parent->right = x;

	if( y != z )
		z->key = y->key;

	if( y->color == "BLACK" )
		RBdelete_fixup(x);

	return y;
}

void RBdelete_fixup( Node* x )
{
	Node* w = new Node();

	Noddy(w);

	if( x == x->parent->left )
	{
		w = x->parent->right;	

		if( w->color == "RED" )
		{
			w->color = "BLACK";
			(x->parent)->color = "RED";
			left_rotate(x->parent);
			w = x->parent->right;
		}

		if( (w->left)->color == "BLACK" && (w->right)->color == "BLACK" )
		{
			w->color = "RED";
			x = x->parent;
		}

		else if( (w->right)->color == "BLACK" )
		{
			(w->left)->color = "BLACK";
			w->color = "RED";
			right_rotate(w);
			w = x->parent->right;
		}

		w->color = (x->parent)->color;
		(x->parent)->color = "BLACK";
		(w->right)->color = "BLACK";
		left_rotate(x->parent);
		x = root;
	}

	else
	{
		w = x->parent->left;	

		if( w->color == "RED" )
		{
			w->color = "BLACK";
			(x->parent)->color = "RED";
			left_rotate(x->parent);
			w = x->parent->left;
		}

		if( (w->left)->color == "BLACK" && (w->left)->color == "BLACK" )
		{
			w->color = "RED";
			x = x->parent;
		}

		else if( (w->left)->color == "BLACK" )
		{
			(w->left)->color = "BLACK";
			w->color = "RED";
			left_rotate(x->parent);
			w = x->parent->left;
		}

		w->color = (x->parent)->color;
		(x->parent)->color = "BLACK";
		(w->left)->color = "BLACK";
		left_rotate(x->parent);
		x = root;
	}

	x->color = "BLACK";
}

void inorder_tree_walk( Node* x )
{	
	if( x != nil )
	{
		inorder_tree_walk(x->left);
		cout << x->key << "\t";
		inorder_tree_walk(x->right);
	}
}

void print_tree( Node* x )
{
	cout << endl;
	inorder_tree_walk(x);
	cout << endl;
}