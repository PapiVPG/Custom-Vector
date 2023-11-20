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
	Vector< int > vector_3;
	
	EXPECT_EQ( vector.size(), SIZE );
	ASSERT_FALSE( vector.empty() );
	ASSERT_FALSE( vector_2.empty() );
	ASSERT_TRUE( vector_3.empty() );
}

TEST( VectorTest, operation_on_vector )
{
	Vector< int > vector( SIZE );

	const int TEST_VALUE = 5;
	vector.push_back( TEST_VALUE );
	EXPECT_EQ( vector[ 0 ], 0 );
	EXPECT_EQ( vector[ SIZE ], TEST_VALUE );

	const int TEST_VALUE_2 = 68;
	vector[ 0 ] = TEST_VALUE_2;
	EXPECT_EQ( vector[ 0 ], TEST_VALUE_2 );

	vector.push_back( TEST_VALUE * 2 );
	EXPECT_EQ( vector[ SIZE + 1 ], TEST_VALUE * 2 );

	vector.pop_back();
	EXPECT_EQ( vector.size(), 6 );

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
	EXPECT_EQ( vector_2[ 4 ], TEST_VALUE_2 );
	EXPECT_EQ( vector_2[ SIZE ], TEST_VALUE );

	Vector< int > vector_3( std::move( vector ) );
	EXPECT_EQ( vector_3[ 4 ], TEST_VALUE_2 );
	EXPECT_EQ( vector_3[ SIZE ], TEST_VALUE );
	EXPECT_EQ( vector.size(), 0 );

	vector_3.push_back( TEST_VALUE * 3 );
	vector = vector_3;
	EXPECT_EQ( vector[ 4 ], TEST_VALUE_2 );
	EXPECT_EQ( vector[ SIZE ], TEST_VALUE );
	EXPECT_EQ( vector[ SIZE + 1 ], TEST_VALUE * 3 );

	vector_3.push_back( TEST_VALUE * 4 );
	vector_2 = std::move( vector_3 );
	EXPECT_EQ( vector_2[ 4 ], TEST_VALUE_2 );
	EXPECT_EQ( vector_2[ SIZE ], TEST_VALUE );
	EXPECT_EQ( vector_2[ SIZE + 1 ], TEST_VALUE * 3 );
	EXPECT_EQ( vector_2[ SIZE + 2 ], TEST_VALUE * 4 );
}


int main( int argc, char** argv )
{
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}
