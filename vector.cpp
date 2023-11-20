#include "vector.h"
#include <cassert>

template< typename T >
Vector< T >::Vector() : m_size( 0 ), m_capacity( 0 ), m_arr( nullptr ){}

template<typename T>
Vector< T >::Vector( const Vector& vector )
{
	m_size = vector.m_size;
	m_capacity = vector.m_capacity;
	m_arr = new T[ m_capacity ];
	for( size_t i = 0; i < m_capacity; i++ )
	{
		m_arr[ i ] = vector[ i ];
	}
}

template< typename T >
Vector< T >::Vector( Vector&& vector ) noexcept
{
	m_size = vector.m_size;
	m_capacity = vector.m_capacity;
	m_arr = vector.m_arr;
	vector.m_capacity = vector.m_size = 0;
	vector.m_arr = nullptr;
}

template< typename T >
Vector< T >::Vector( size_t size ) : m_arr( new T[ size ] ), m_size( 0 ), m_capacity( size ){}

template< typename T >
Vector< T >& Vector< T >::operator=( const Vector< T >& vector )
{
	if( this != &vector )
	{
		if( m_arr )
		{
			delete[] m_arr;
		}
		m_capacity = vector.m_capacity;
		m_size = vector.m_size;
		m_arr = new T[ m_capacity ];
		m_arr = vector.m_arr;
	}
	return *this;
}

template<typename T>
Vector< T >& Vector< T >::operator=( Vector< T >&& vector ) noexcept
{
	if( this != &vector )
	{
		m_capacity = vector.m_capacity;
		m_size = vector.m_size;
		m_arr = vector.m_arr;
		vector.m_capacity = vector.m_size = 0;
		vector.m_arr = nullptr;
	}
	return *this;
}

template< typename T >
void Vector< T >::push_back( const T& value )
{
	if( m_size == m_capacity )
	{
		new_allocation();
	}
	m_arr[ m_size++ ] = value;
}

template< typename T >
void Vector< T >::new_allocation()
{
	m_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
	T* tempArr = new T[ m_capacity ];
	if( m_arr != nullptr )
	{
		for( size_t i = 0; i < m_capacity; ++i )
		{
			tempArr[ i ] = m_arr[ i ];
		}
		delete[] m_arr;
	}
	m_arr = tempArr;
}

template< typename T >
bool Vector< T >::empty()
{
	return m_size == 0;
}

template< typename T >
size_t Vector< T >::size() const
{
	return m_size;
}

template< typename T >
size_t Vector< T >::capacity() const
{
	return m_capacity;
}

template< typename T >
void Vector< T >::pop_back()
{
	if( !empty() )
	{
		--m_size;
	}
}

template< typename T >
void Vector< T >::clear()
{
	m_capacity = m_size = 0;
	if ( m_arr )
	{
		delete[] m_arr;
	}
	m_arr = nullptr;
}

template< typename T >
T& Vector< T >::operator[]( size_t index ) const
{
	assert( ( "index is bigger than size of the vector", index < m_capacity ) );
	return m_arr[ index ];
}

template< typename T >
T* Vector< T >::begin()
{
	return m_size > 0 ? m_arr : nullptr;
}

template< typename T >
T* Vector< T >::end()
{
	return m_arr + m_size;
}

template< typename T >
T* get_arr( Vector< T >& vector )
{
	return vector.m_arr;
}
