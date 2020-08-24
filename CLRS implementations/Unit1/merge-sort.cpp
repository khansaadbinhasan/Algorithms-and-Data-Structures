#include <bits/stdc++.h>

using namespace std;

void MergeSort( vector<int> &A, int p, int r );
void Merge( vector<int> &A, int p, int q, int r );

int main()
{
	vector<int> A;

	int num;

	cout << "Enter number of elements: ";
	cin >> num;
	cout << endl;

	cout << "Enter array: ";

	for (int i = 0; i < num; ++i)
	{
		int temp;

		cin >> temp;

		A.push_back(temp); 
	}

	MergeSort( A, 0, A.size() - 1 );

	cout << "Sorted array: ";
	for (int i = 0; i < A.size(); ++i)
	{
		cout << A[i] << " ";
	}

	cout << endl;
}

void MergeSort( vector<int> &A, int p, int r )
{
	if( p < r )
	{
		int q = (p+r)/2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}	
}

void Merge( vector<int> &A, int p, int q, int r )
{
	int n = q - p + 1;
	int m = r - q;

	vector<int> B( A.begin() + p, A.begin() + q + 1 );
	vector<int> C( A.begin() + q + 1, A.begin() + q + m + 1);

	int I = 0;
	int J = 0;

	B.resize(n);
	C.resize(m);

	B[n] = 10000;
	C[m] = 10000;

	
	for( int k = p; k <= r; k++ )
	{
		if( B[I] <= C[J] )
		{
			A[k] = B[I];
			I++;
		}

		else
		{
			A[k] = C[J];
			J++;
		}
	}
}






// A.push_back(8);	A.push_back(3); A.push_back(4);	A.push_back(1);	A.push_back(0);
// A.push_back(7);	A.push_back(6);	A.push_back(2);	A.push_back(4);	A.push_back(5);
// A.push_back(11); A.push_back(12); A.push_back(13); 


// cout << "A: ";

// 	for (int i = 0; i < A.size(); ++i)
// 	{
// 		cout << A[i] << " ";
// 	}

// 	cout << endl;
// 	cout << "B: ";

// 	for (int i = 0; i < B.size(); ++i)
// 	{
// 		cout << B[i] << " ";
// 	}

// 	cout << endl;
// 	cout << "C: ";

// 	for (int i = 0; i < C.size(); ++i)
// 	{
// 		cout << C[i] << " ";
// 	}

// 	cout << endl;
// 	cout << "p: " << p << endl;
// 	cout << "q: " << q << endl;
// 	cout << "r: " << r << endl;
// 	cout << "n: " << n << endl;
// 	cout << "m: " << m << endl;
// 	cout << endl << endl;
