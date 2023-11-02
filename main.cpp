#include <iostream>
#include "vector.h"
#include "vector.cpp"
#include <gtest/gtest.h>

using namespace std;

TEST( VectorTest, initialization )
{
	const size_t SIZE = 5;
	Vector<int> vector( SIZE );
	Vector<int> vector_2;
	
	EXPECT_EQ( vector.size(), SIZE );
	ASSERT_FALSE( vector.empty() );
	ASSERT_TRUE( vector_2.empty() );
}

TEST( VectorTest, operation_on_vector )
{
	const size_t SIZE = 5;
	Vector<int> vector( SIZE );

	const int TEST_VALUE = 5;
	vector.push_back( TEST_VALUE );
	EXPECT_EQ( vector[ 0 ], TEST_VALUE );

	vector.push_back( TEST_VALUE * 2 );
	EXPECT_EQ( vector[ 1 ], TEST_VALUE * 2 );
	EXPECT_EQ( vector.capacity(), 2 );

	vector.pop_back();
	EXPECT_EQ( vector.size(), 4 );

	vector.clear();
	EXPECT_EQ( vector.size(), 0 );

}

int main( int argc, char** argv )
{
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
