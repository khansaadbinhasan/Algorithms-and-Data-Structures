#include <iostream>

int main()
{
	int A[]={6,5,4,3,2,1};

	for( int i = 0; i < 6; i++)
	{
		for( int j = i + 1; j < 6; j++ )
		{
			int temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	}


	for( int i = 0; i < 6; i++ )
	{
		std::cout << A[i] << std::endl;
	}
}
