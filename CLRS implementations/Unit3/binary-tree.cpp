#include <iostream>

using namespace std;

class Node
{
public:
	int key;
	Node* left;
	Node* right;
	Node* parent;

	Node()
	{
		this->left = NULL;
		this->right = NULL;
	}
};

void preorder_tree_walk( Node* x );
void inorder_tree_walk( Node* x );
void postorder_tree_walk( Node* x );
Node* tree_search(Node* x, Node* k);
Node* tree_minimum( Node* x );
Node* tree_maximum( Node* x);
Node* tree_successor( Node* x );
void tree_insert( Node* &root, Node* z );
void tree_delete( Node* &root, Node* z );
void print_tree( Node* &root );
void demo();

int main()
{
	demo();	
}

void demo()
{
	Node* root = new Node();
	Node* z1 = new Node();
	Node* z2 = new Node();
	Node* z3 = new Node();
	Node* z4 = new Node();
	Node* z5 = new Node();

	root = NULL;

	z1->key = 10;
	z2->key = 20;
	z3->key = 40;
	z4->key = 50;
	z5->key = 0;

	cout << "Tree before insertion: " << endl;
	print_tree(root);

	tree_insert( root, z1 );	
	tree_insert( root, z2 );	
	tree_insert( root, z3 );	
	tree_insert( root, z4 );	

	cout << "Tree after insertion: " << endl;
	print_tree(root);

	Node* temp = tree_search(root, z4);
	cout << "z4 " << " occurs at: " << temp << endl;
	
	temp = tree_search(root, z5);
	cout << "z5 occurs at: " << temp << endl;

	temp = tree_minimum( root );
	cout << "Minimum for tree is: " << temp->key << endl;

	temp = tree_maximum( root );
	cout << "Maximum for tree is: " << temp->key << endl;

	temp = tree_successor( root );
	cout << "Successor for: " << root->key << endl << "is: " << temp->key << endl;

	tree_insert( root, z5 );
	cout << "Tree after insertion: " << endl;
	print_tree(root);

	tree_delete( root, z3 );
	cout << "Tree after deletion: " << endl;
	print_tree(root);

}

void preorder_tree_walk( Node* x )
{	
	if( x != NULL )
	{
		cout << x->key << "\t";
		preorder_tree_walk(x->left);
		preorder_tree_walk(x->right);
	}
}


void inorder_tree_walk( Node* x )
{	
	if( x != NULL )
	{
		inorder_tree_walk(x->left);
		cout << x->key << "\t";
		inorder_tree_walk(x->right);
	}
}


void postorder_tree_walk( Node* x )
{	
	if( x != NULL )
	{
		postorder_tree_walk(x->left);
		postorder_tree_walk(x->right);
		cout << x->key << "\t";
	}
}

Node* tree_search(Node* x, Node* k)
{
	while( x != NULL && x->key != k->key )
	{
		if( k->key > x->key )
			x = x->right;
	
		else if( k->key < x->key )
			x = x->left;
	}

	return x;
}

Node* tree_minimum( Node* x )
{
	while( x->left != NULL )
		x = x->left;

	return x;
}

Node* tree_maximum( Node* x)
{
	while( x->right != NULL )
		x = x->right;

	return x;
}

Node* tree_successor( Node* x )
{
	Node* y = new Node();

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

void tree_insert( Node* &root, Node* z )
{
	Node* x = new Node();
	Node* y = new Node();

	x = root;
	y = NULL;

	while( x != NULL )
	{
		y = x;

		if( z->key < x->key )
			x = x->left;

		else 
			x = x->right;
	}

	z->parent = y;

	if( y == NULL )
		root = z; 

	else if( z->key > y->key )
		y->right = z;

	else
		y->left = z;
}

void tree_delete( Node* &root, Node* z )
{
	Node* x = new Node();
	Node* y = new Node();

	if( z->left == NULL || z->right == NULL )
		y = z;
	else
		y = tree_successor(z);


	if( y->left != NULL )
		x = y->left;
	else
		x = y->right;


	if( x != NULL )
		x->parent = y->parent;


	if( y->parent == NULL )
		root = x;
	else if( y == y->parent->left )
		y->parent->left = x;
	else
		y->parent->right = x;

	if( y != z )
		z->key = y->key;

}


void print_tree( Node* &x )
{
	cout << endl;
	inorder_tree_walk(x);
	cout << endl;
}