#include <iostream>
#include <vector>

using namespace std;

void matrix_chain_order();
void print_optimal_parents(int i, int j);

int m[1000][1000];
int s[1000][1000];
int p[1000];
int n = 7;

int main()
{
	// p[0] = 30;
	// p[1]=  35;
	// p[2] = 15;
	// p[3] = 5;
	// p[4] = 10;
	// p[5] = 20;
	// p[6] = 25;

	p[0] = 5;
	p[1]= 10;
	p[2] = 3;
	p[3] = 12;
	p[4] = 5;
	p[5] = 50;
	p[6] = 6;


	matrix_chain_order();
	print_optimal_parents(1,6);

	cout << endl;
}



void matrix_chain_order()
{
	for (int i = 1; i < n; ++i)
		m[i][i] = 0;

	for (int l = 2; l < n; ++l)
	{
		for (int i = 1; i < n - l + 2; ++i)
		{
			int j = i + l - 1;
			m[i][j] = 1000000;

			for (int k = i; k < j; ++k)
			{
				int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

				if( q < m[i][j] )
				{
					m[i][j] = q;
					s[i][j] = k;
				}

			}
		}
	}
}

void print_optimal_parents(int i, int j)
{
	if (i == j)
		cout << "A" << i;

	else
	{
		cout << "(";
		print_optimal_parents( i , s[i][j] );
		print_optimal_parents( s[i][j] + 1 , j );
		cout << ")";
	}
}