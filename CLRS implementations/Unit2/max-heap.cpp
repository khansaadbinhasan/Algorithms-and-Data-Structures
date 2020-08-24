#include <bits/stdc++.h>

using namespace std;


int parent( int i);
int left( int i);
int right( int i);
void max_heapify( vector<int> &A , int i );
void build_max_heap( vector<int> &A );
vector<int> heap_sort( vector<int> A );
int heap_maximum( vector<int> &A );
int heap_extract_max( vector<int> &A );
void heap_increase_key( vector<int> &A, int i, int key );
void max_heap_insert( vector<int> &A, int key );
void print_this( vector<int> &A );

int COUNT = 0;

int main()
{
	vector<int> A;

	A.push_back(8);	A.push_back(3); A.push_back(4);	A.push_back(1);	A.push_back(0);
	A.push_back(7);	A.push_back(6);	A.push_back(2);	A.push_back(4);	A.push_back(5);

	cout << "Initial Vector: ";
	build_max_heap(A);
	print_this(A);

	vector<int> B = heap_sort(A);
	cout << "After Heap Sort: ";
	print_this(B);
	
	int max = heap_extract_max(A);
	cout << "Maximum for heap is: " << max << endl << endl;
	
	max = heap_maximum(A);
	cout << "Maximum for heap after extraction is: " << max << endl << endl;

	int i = 4;
	int key = -1;

	heap_increase_key(A, i, key);
	cout << endl << "Heap after increasing key at " << i << " to " << key << " : " ;
	print_this(A);

	max_heap_insert(A, key);
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

void max_heapify( vector<int> &A , int i )
{
	int l = left(i);
	int r = right(i);

	int largest;

	if( l < A.size() && A[l] > A[i] )
		largest = l;

	else
		largest = i;

	if( r < A.size() && A[r] > A[largest] )
		largest = r;

	if( largest != i )
	{
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;

		max_heapify(A, largest);
	}
}

void build_max_heap( vector<int> &A )
{
	for ( int i = A.size() / 2; i >= 0 ; i-- )
	{
		max_heapify(A, i);		
	}
}

vector<int> heap_sort( vector<int> A )
{
	build_max_heap(A);

	vector<int> B = A;

	for (int i = A.size() - 1; i >= 0; i-- )
	{
		B[i] = A[0];

		int temp = A[0];
		A[0] = A[i];
		A[i] = temp;

		A.pop_back();

		max_heapify(A, 0);
	}

	return B;
}

int heap_maximum( vector<int> &A )
{
	return A[0];
}

int heap_extract_max( vector<int> &A )
{
	if( A.size() < 1 )
	{
		cout << "Get a heap man!!!";
		return -100000;
	}

	int max = A[0];
	A[0] = A[ A.size() - 1 ];

	A.resize( A.size() - 1 );

	max_heapify(A, 0);

	return max;
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

void max_heap_insert( vector<int> &A, int key )
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
