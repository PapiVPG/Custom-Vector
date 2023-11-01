#include <iostream>
#include "vector.h"
#include "vector.cpp"

using namespace std;

int main()
{
	Vector<int> vector;
	Vector<int> vector_2(5);

	for( size_t i = 0; i < 5; i++ )
	{
		vector.push_back( i * 5 );
	}
	cout << "size " << vector_2.size() << endl;
	Vector<int> vector_3( vector );
	Vector<int> vector_4( std::move( vector ) );

	for( size_t i = 0; i < 5; i++ )
	{
		vector_2.push_back( i * 25 );
	}
	cout << "size " << vector_2.size() << endl;
	//for( size_t i = 0; i < 5; i++ )
	//{
	//	cout<<vector[ i ]<<" ";
	//}
	cout << endl;

	for( auto& x : vector_2 )
		cout << x << endl;

	for( auto& x : vector_3 )
		cout << x << endl;

	for( auto& x : vector_4 )
		cout << x << endl;

	return 0;
}
