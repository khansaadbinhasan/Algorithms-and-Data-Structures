#include <bits/stdc++.h>

using namespace std;


void quick_sort(vector<int> &A, int p, int r);
int partition( vector<int> &A, int p, int r );
void print_this( vector<int> &A );
int randomized_partition( vector<int> &A, int p, int r );

int COUNT = 0;

int main()
{
	// for g++ -v > c++11
	// vector<int> A{9,8,7,6,5,4,3,2,1};

	vector<int> A;

	A.push_back(8);	A.push_back(3); A.push_back(4);	A.push_back(1);	A.push_back(0);
	A.push_back(7);	A.push_back(6);	A.push_back(2);	A.push_back(4);	A.push_back(5);

	int p = 0;
	int r = A.size() - 1;

	cout << "Before: ";
	print_this(A);
	quick_sort(A, p, r);	
	cout << "After: ";
	print_this(A);

	cout << "Total COUNT: " << COUNT << endl;

}


void quick_sort(vector<int> &A, int p, int r)
{
	if( p < r )
	{
		COUNT++;

		// int q = partition( A, p, r );
		int q = randomized_partition( A, p, r );
		quick_sort(A, p, q - 1);
		quick_sort(A, q + 1, r);
	}
}

int randomized_partition( vector<int> &A, int p, int r )
{
	int i = p + ( std::rand() % ( r - p ) );

	int temp = A[i];
	A[i] = A[r];
	A[r] = temp;

	return partition(A, p, r);
}

int partition( vector<int> &A, int p, int r )
{
	int x = A[r];
	int i = p - 1;

	for (int j = p; j < r ; ++j)
	{
		if( A[j] <= x )
		{
			i++;

			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}

	int temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;

	return i+1;
}

void print_this( vector<int> &A )
{
	for (int i = 0; i < A.size(); ++i)
	{
		cout << A[i] << " ";
	}

	cout << endl << endl;
}
