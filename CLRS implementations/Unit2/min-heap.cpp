#include <bits/stdc++.h>

using namespace std;


int parent( int i);
int left( int i);
int right( int i);
void min_heapify( vector<int> &A , int i );
void build_min_heap( vector<int> &A );
vector<int> heap_sort( vector<int> A );
int heap_minimum( vector<int> &A );
int heap_extract_min( vector<int> &A );
void heap_increase_key( vector<int> &A, int i, int key );
void min_heap_insert( vector<int> &A, int key );
void print_this( vector<int> &A );

int COUNT = 0;

int main()
{
	vector<int> A;

	A.push_back(8);	A.push_back(3); A.push_back(4);	A.push_back(1);	A.push_back(0);
	A.push_back(7);	A.push_back(6);	A.push_back(2);	A.push_back(4);	A.push_back(5);

	cout << "Initial Vector: ";
	build_min_heap(A);
	print_this(A);

	vector<int> B = heap_sort(A);
	cout << "After Heap Sort: ";
	print_this(B);
	
	int min = heap_extract_min(A);
	cout << "minimum for heap is: " << min << endl << endl;
	
	min = heap_minimum(A);
	cout << "minimum for heap after extraction is: " << min << endl << endl;

	int i = 4;
	int key = -1;

	heap_increase_key(A, i, key);
	cout << endl << "Heap after increasing key at " << i << " to " << key << " : " ;
	print_this(A);

	min_heap_insert(A, key);
	cout << "After inserting key " << key << " heap now: ";
	print_this(A);
}

int parent( int i )
{
	return i / 2;
}

int left( int i )
{
	return 2 * i;
}

int right( int i )
{
	return 2 * i + 1;
}

void min_heapify( vector<int> &A , int i )
{
	int l = left(i);
	int r = right(i);

	int smallest;

	if( l < A.size() && A[l] < A[i] )
		smallest = l;

	else
		smallest = i;

	if( r < A.size() && A[r] < A[smallest] )
		smallest = r;

	if( smallest != i )
	{
		int temp = A[i];
		A[i] = A[smallest];
		A[smallest] = temp;

		min_heapify(A, smallest);
	}
}

void build_min_heap( vector<int> &A )
{
	for ( int i = A.size() / 2; i >= 0 ; i-- )
	{
		min_heapify(A, i);		
	}
}

vector<int> heap_sort( vector<int> A )
{
	build_min_heap(A);

	vector<int> B = A;

	for (int i = A.size() - 1; i >= 0; i-- )
	{
		B[i] = A[0];

		int temp = A[0];
		A[0] = A[i];
		A[i] = temp;

		A.pop_back();

		min_heapify(A, 0);
	}

	return B;
}

int heap_minimum( vector<int> &A )
{
	return A[0];
}

int heap_extract_min( vector<int> &A )
{
	if( A.size() < 1 )
	{
		cout << "Get a heap man!!!";
		return -100000;
	}

	int min = A[0];
	A[0] = A[ A.size() - 1 ];

	A.resize( A.size() - 1 );

	min_heapify(A, 0);

	return min;
}

void heap_increase_key( vector<int> &A, int i, int key )
{
	if( key < A[i] )
	{
		cout << "Provided key is less than present key";
		return;
	}

	A[i] = key;

	while( A[i] > A[parent(i)] && i >= 0 )
	{
		int temp = A[i];
		A[i] = A[parent(i)];
		A[parent(i)] = temp;

		i = parent(i);
	}
}

void min_heap_insert( vector<int> &A, int key )
{
	A.push_back(-1000);
	heap_increase_key(A, A.size() - 1, key);
}

void print_this( vector<int> &A )
{
	for (int i = 0; i < A.size(); ++i)
	{
		cout << A[i] << " ";
	}

	cout << endl << endl;
}
