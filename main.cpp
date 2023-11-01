#include <iostream>
#include "vector.h"
#include "vector.cpp"

using namespace std;

int main()
{
	Vector<int> vector;

	for( size_t i = 0; i < 5; i++ )
	{
		vector.push_back( i * 5 );
	}

	//for( size_t i = 0; i < 4; i++ )
	//{
	//	cout<<vector[ i ]<<" ";
	//}

	for( auto& x : vector )
		cout << x << endl;

	return 0;
}
