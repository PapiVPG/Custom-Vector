#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>

template< typename T >
class Vector {
public:
	explicit Vector();
	explicit Vector( const Vector& vector );
	explicit Vector( Vector&& vector ) noexcept;
	explicit Vector( const size_t size );
	explicit Vector( const std::initializer_list< T > ilist );
	~Vector() { clear(); };

	void push_back( const T& value );
	bool empty();
	void assign( size_t count, const T& value );
	size_t size() const;
	void resize( const size_t count );
	size_t capacity() const;
	void pop_back();
	T& at( const size_t pos ) const;
	T& front() const;
	T& back() const;
	void clear();

	Vector< T >& operator=( const Vector< T >& vector );
	Vector< T >& operator=( Vector< T >&& vector ) noexcept;
	T& operator[]( const size_t index );
	T* begin();
	T* end();
	const T* cbegin();
	const T* cend();

private:
	T* m_arr;
	size_t m_size;
	size_t m_capacity;
	void new_allocation();
};

#endif
