#include <iostream>
#include "vector.h"
#include "vector.cpp"
#include <gtest/gtest.h>

using namespace std;
const size_t SIZE = 5;

TEST( VectorTest, initialization )
{
	Vector< int > vector{ 1, 3, 4, 5, 7 };
	Vector< int > vector_2( SIZE );
	
	EXPECT_EQ( vector.size(), SIZE );
	ASSERT_FALSE( vector.empty() );
	ASSERT_TRUE( vector_2.empty() );
}

TEST( VectorTest, operation_on_vector )
{
	Vector< int > vector( SIZE );

	const int TEST_VALUE = 5;
	vector.push_back( TEST_VALUE );
	EXPECT_EQ( vector[ 0 ], TEST_VALUE );

	vector[ 0 ] = 68;
	EXPECT_EQ( vector[ 0 ], 68 );

	vector.push_back( TEST_VALUE * 2 );
	EXPECT_EQ( vector[ 1 ], TEST_VALUE * 2 );

	vector.pop_back();
	EXPECT_EQ( vector.size(), 1 );

	vector.clear();
	EXPECT_EQ( vector.size(), 0 );
}

TEST( VectorTest, constructor_tests )
{
	Vector< int > vector( SIZE );
	const int TEST_VALUE = 45;
	const int TEST_VALUE_2 = 4;
	vector.push_back( TEST_VALUE );
	vector[ 4 ] = TEST_VALUE_2;
	Vector< int > vector_2( vector );
	EXPECT_EQ( vector_2[ 0 ], TEST_VALUE );
	EXPECT_EQ( vector_2[ 4 ], TEST_VALUE_2 );

	Vector< int > vector_3( std::move( vector ) );
	EXPECT_EQ( vector_3[ 0 ], TEST_VALUE );
	EXPECT_EQ( vector_3[ 4 ], TEST_VALUE_2 );
	EXPECT_EQ( vector.size(), 0 );

	vector_3.push_back( TEST_VALUE * 3 );
	vector = vector_3;
	EXPECT_EQ( vector[ 0 ], TEST_VALUE );
	EXPECT_EQ( vector[ 1 ], TEST_VALUE * 3 );
	EXPECT_EQ( vector[ 4 ], TEST_VALUE_2 );

	vector_3.push_back( TEST_VALUE * 4 );
	vector_2 = std::move( vector_3 );
	EXPECT_EQ( vector_2[ 0 ], TEST_VALUE );
	EXPECT_EQ( vector_2[ 1 ], TEST_VALUE * 3 );
	EXPECT_EQ( vector_2[ 2 ], TEST_VALUE * 4 );
	EXPECT_EQ( vector_2[ 4 ], TEST_VALUE_2 );
}

int main( int argc, char** argv )
{
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
