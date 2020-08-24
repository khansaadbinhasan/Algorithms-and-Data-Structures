#include <bits/stdc++.h>

using namespace std;

void counting_sort( vector<int> &A, vector<int> &B, int k );
void fill_with_random( vector<int> &A, int start, int end );
void print_this( vector<int> &A );

int main()
{
	vector<int> A;

	int start = 0;
	int end = 20;

	fill_with_random(A,start,end);
	cout << "Before Sorting: ";
	print_this(A);

	vector<int> B = A;

	int k = 25;
	counting_sort( A, B, k );

	cout << endl << "After Sorting: ";
	print_this(B);
}


void counting_sort( vector<int> &A, vector<int> &B, int k )
{

	vector<int> C;
	C.resize(k);

	for (int i = 0; i < k; ++i)
	{
		C[i] = 0;
	}

	for (int i = 0; i < A.size(); ++i)
	{
		C[A[i]] = C[A[i]] + 1;
	}


	for (int i = 1; i < k; ++i)
	{
		C[i] = C[i-1] + C[i];
	}


	for (int i = A.size() - 1; i >= 0; i--)
	{
		B[C[A[i]] - 1] = A[i];
		C[A[i]] = C[A[i]] - 1;
	}
}

void print_this( vector<int> &A )
{
	for (int i = 0; i < A.size(); ++i)
	{
		cout << A[i] << " ";
	}

	cout << endl << endl;
}

void fill_with_random( vector<int> &A, int start, int end )
{
	int size = end - start;

	for (int i = 0; i < size; ++i)
	{
		int random = start + ( std::rand() % ( end - start ) );
		A.push_back(random);
	}
}


// cout << "A: "; print_this(A);
// cout << "B: "; print_this(B);
// cout << "C: "; print_this(C);

// cout << "A[" << i << "]: " << A[i] << "\t";
// cout << "C[A[" << i << "]]: " << C[A[i]] << "\t";
// cout << "B[C[A[" << i << "]]: " << B[C[A[i]]] << endl;
