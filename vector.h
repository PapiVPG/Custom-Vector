#ifndef VECTOR_H
#define VECTOR_H

template< typename T >
class Vector {
	T* arr;
	size_t m_size;
	size_t m_capacity;
public:
	Vector();
	Vector( const Vector& vector );
	Vector( Vector&& vector );
	Vector( size_t size );
	~Vector() { delete[] arr; m_size = m_capacity = 0; arr = nullptr; };

	void new_allocation();
	void push_back( T value );
	bool empty();
	size_t size() const;
	size_t capacity() const;
	void pop_back();
	void clear();

	Vector< T >& operator=( const Vector< T >& vector );
	Vector< T >& operator=( Vector< T >&& vector );
	T& operator[]( size_t index ) const;
	T* begin();
	T* end();

	friend T* get_arr( Vector< T >& vector );
};

#endif

