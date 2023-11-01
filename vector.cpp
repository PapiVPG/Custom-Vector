#include "vector.h"
#include <cassert>

template< typename T >
Vector< T >::Vector() : m_size( 0 ), m_capacity( 0 ), arr( nullptr ){};

template<typename T>
Vector<T>::Vector( Vector& vector )
{
	m_size = m_capacity = vector.size();
	arr = new T[ m_size ];
	for( size_t i = 0; i < m_size; i++ )
	{
		arr[ i ] = vector[ i ];
	}
};

template<typename T>
Vector<T>::Vector( Vector&& vector )
{
	m_size = m_capacity = vector.size();

	arr = new T[ m_size ];
	for( size_t i = 0; i < m_size; i++ )
	{
		arr[ i ] = vector[ i ];
	}
	vector.~Vector();
};

template< typename T >
Vector< T >::Vector( size_t size ) : arr( new T[ size ] ), m_size( size )
{
	m_capacity = 0;
};

template< typename T >
void Vector< T >::push_back( T value )
{
	if( m_size == m_capacity )
	{
		new_allocation();
		arr[ m_size++ ] = value;
	}
	else
	{
		arr[ m_capacity ] = value;
	}
	++m_capacity;
}

template< typename T >
void Vector< T >::new_allocation()
{
	T* temp = new T[ m_size + 1 ];
	for( size_t i = 0; i < m_size; ++i )
	{
		temp[ i ] = arr[ i ];
	}
	delete []arr;
	arr = temp;
}

template< typename T >
bool Vector< T >::empty()
{
	return m_size == 0;
}

template<typename T>
size_t Vector<T>::size()
{
	return m_size;
}

template<typename T>
size_t Vector<T>::capacity()
{
	return m_capacity;
}

template< typename T >
void Vector< T >::pop_back()
{
	if( empty() )
	{
		return;
	}
	--m_size;
}

template< typename T >
void Vector< T >::clear()
{
	m_size = 0;
	for( auto& element : arr )
		element = 0;
}

template< typename T >
T Vector< T >::operator[]( size_t index )
{
	assert( ( "index is bigger than size of the vector", index < m_size ) );
	return arr[ index ];
}

template<typename T>
T* Vector<T>::begin()
{
	return m_size > 0 ? arr : nullptr;
}

template<typename T>
T* Vector<T>::end()
{
	return arr + m_size;
}

