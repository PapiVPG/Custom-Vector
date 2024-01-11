#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>

template< typename T >
class Vector {
public:
	typedef T* iterator;
	typedef const T* const_iterator;

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
	void reserve( const size_t count );
	size_t capacity() const;
	void pop_back();
	T& at( const size_t pos ) const;
	T& front() const;
	T& back() const;
	T* data() const noexcept;
	void clear();
	iterator insert( const_iterator position, const T& val );

	Vector< T >& operator=( const Vector< T >& vector );
	Vector< T >& operator=( Vector< T >&& vector ) noexcept;
	T& operator[]( const size_t index );
	T* begin() const;
	T* end() const;
	const T* cbegin() const;
	const T* cend() const;
	T* rbegin() const;
	T* rend() const;
	const T* crbegin() const;
	const T* crend() const;

private:
	T* m_arr;
	size_t m_size;
	size_t m_capacity;
	void new_allocation();
};

#endif
