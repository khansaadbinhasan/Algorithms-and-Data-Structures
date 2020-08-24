#include <iostream>

using namespace std;

void initialize( int* e, int* x);
void fastest_way( int* e, int* x, int n, int &fstar, int &lstar);
void print_way( int n, int lstar );



int N = 3;
int n = 6;


int a[3][6];
int t[3][6];
int f[3][6];
int l[3][6];


int main()
{
	// int N = 3;
	// int n = 6;
	
	int e[N];
	int x[N];

	int lstar = -1000;
	int fstar = -1000;


	initialize( e, x);

	fastest_way( e, x, n, fstar, lstar );	
	cout << "Value of f*:\t" << fstar << endl;
	cout << "Value of l*:\t" << lstar << endl;
	print_way( n, lstar);

	return 0;

}


void initialize( int* e, int* x)
{
	a[0][0] = 7; a[0][1] = 9; a[0][2] = 3; a[0][3] = 4; a[0][4] = 8; a[0][5] = 4;
	a[1][0] = 8; a[1][1] = 5; a[1][2] = 6; a[1][3] = 4; a[1][4] = 5; a[1][5] = 7;

	t[0][0] = 2; t[0][1] = 3; t[0][2] = 1; t[0][3] = 3; t[0][4] = 4;
	t[1][0] = 2; t[1][1] = 1; t[1][2] = 2; t[1][3] = 2; t[1][4] = 1;

	e[0] = 2; e[1] = 4;
	x[0] = 3; x[1] = 2;
}

void fastest_way( int* e, int* x, int n, int &fstar, int &lstar)
{

	f[0][0] = e[0] + a[0][0];
	f[1][0] = e[1] + a[1][0];

	for (int i = 1; i < n; ++i)
	{
		if( f[0][i-1] + a[0][i] <= f[1][i-1] + t[1][i-1] + a[0][i])
		{
			f[0][i] = f[0][i-1] + a[0][i];
			l[0][i] = 0;
		}

		else
		{
			f[0][i] = f[1][i-1] + t[1][i-1] + a[0][i];
			l[0][i] = 1;
		}

		if( f[1][i-1] + a[1][i] < f[0][i-1] + t[0][i-1] + a[1][i] )
		{
			f[1][i] = f[1][i-1] + a[1][i];
			l[1][i] = 1;
		}

		else
		{
			f[1][i] = f[0][i-1] + t[0][i-1] + a[1][i];
			l[1][i] = 0;
		}
	}

	if( f[0][n-1] + x[0] <= f[1][n-1] + x[1] )
	{
		fstar = f[0][n-1] + x[0];
		lstar = 0;
	}

	else
	{
		fstar = f[1][n-1] + x[1];
		lstar = 1;
	}

	for (int i = n - 1; i >= 1; i--)
	{
		cout << l[0][i] << "\t";
	}

	cout << endl;

	for (int i = n - 1; i >= 1; i--)
	{
		cout << l[1][i] << "\t";
	}

	cout << endl;
}


void print_way( int n, int lstar )
{
	int i = lstar;

	cout << "line " << i + 1 << ", station " << n << endl;	

	for (int j = n - 1; j > 1; j--)
	{
		i = l[i][j];
		cout << "line " << i + 1 << ", station " << j << endl;
	}
}