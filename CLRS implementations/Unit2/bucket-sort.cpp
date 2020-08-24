#include <bits/stdc++.h>

using namespace std;

void bucket_sort(vector<int> &A);
void insertion_sort( vector<int> &A );
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
		int random = start + ( std::rand() % size );
		A.push_back(random);
	}
}

void insertion_sort( vector<int> &A )
{
	for( int i = 0; i < A.size(); i++)
	{
		for( int j = i + 1; j < A.size(); j++ )
		{
			int temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	}
}