#include "vector.h"
#include <string>
#include <cassert>
#include <iostream>
#include <stdexcept>

template< typename T >
Vector< T >::Vector() : m_size( 0 ), m_capacity( 0 ), m_arr( nullptr ){}

template<typename T>
Vector< T >::Vector( const Vector& vector )
{
	try
	{
		m_size = vector.m_size;
		m_capacity = vector.m_capacity;
		m_arr = new T[ m_capacity ];
		for( size_t i = 0; i < m_capacity; i++ )
		{
			m_arr[ i ] = vector.m_arr[ i ];
		}
	}
	catch( std::bad_alloc& e )
	{
		std::cerr<<e.what()<<std::endl;
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
Vector< T >::Vector( const size_t size ) : m_size( 0 ), m_capacity( size )
{
	try
	{
		m_arr( new T[ size ] );
	}
	catch( std::bad_alloc& e )
	{
		std::cerr<<e.what()<<std::endl;
	}
}

template< typename T >
Vector< T >::Vector( const std::initializer_list< T > ilist ) : Vector()
{
	for (auto& elem : ilist)
	{
		push_back( elem );
	}
}

template< typename T >
Vector< T >& Vector< T >::operator=( const Vector< T >& vector )
{
	if( this != &vector )
	{
		try
		{
			if ( m_arr )
			{
				delete[] m_arr;
			}
			m_capacity = vector.m_capacity;
			m_size = vector.m_size;
			m_arr = new T[ m_capacity ];
			m_arr = vector.m_arr;
		}
		catch( std::bad_alloc& e )
		{
			std::cerr<<e.what()<<std::endl;
		}
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
	try
	{
		m_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
		T* tempArr = new T[ m_capacity ];
		if ( m_arr != nullptr )
		{
			for ( size_t i = 0; i < m_capacity; ++i )
			{
				tempArr[ i ] = m_arr[ i ];
			}
			delete[] m_arr;
		}
		m_arr = tempArr;
	}
	catch( std::bad_alloc& e )
	{
		std::cerr<<e.what()<<std::endl;
	}
}

template< typename T >
bool Vector< T >::empty()
{
	return m_size == 0;
}

template<typename T>
void Vector<T>::assign( size_t count, const T& value )
{
	clear();
	while ( count-- )
	{
		push_back( value );
	}
}

template< typename T >
size_t Vector< T >::size() const
{
	return m_size;
}

template<typename T>
void Vector<T>::resize( const size_t count )
{
	if ( count > m_size )
	{
		while ( count > m_capacity )
		{
			new_allocation();
		}
		m_size = count;
	}
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

template<typename T>
T& Vector<T>::at(const size_t pos) const
{
	if( pos >= m_size )
	{
		throw "at(): " + std::to_string( pos ) + "Position out of range\n";
	}
	return m_arr[ pos ];
}

template<typename T>
T& Vector<T>::front() const
{
	if( m_arr )
	{
		return *m_arr;
	}
	T temp;
	return temp;
}

template<typename T>
T& Vector<T>::back() const
{
	if( m_arr )
	{
		return m_arr[ m_size - 1 ];
	}
	T temp;
	return temp;
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
T& Vector< T >::operator[]( const size_t index )
{
	assert( ( "index is bigger than size of the vector", index < m_capacity ) );
	return m_arr[ index ];
}

template< typename T >
T* Vector< T >::begin()
{
	return m_size > 0 ? m_arr : nullptr;
}

template<typename T>
const T* Vector<T>::cbegin()
{
	return m_size > 0 ? m_arr : nullptr;
}

template< typename T >
T* Vector< T >::end()
{
	return m_arr + m_size;
}

template<typename T>
const T* Vector<T>::cend()
{
	return m_size > 0 ? m_arr : nullptr;
}
