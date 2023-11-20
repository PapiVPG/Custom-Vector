#ifndef VECTOR_H
#define VECTOR_H

template< typename T >
class Vector {
public:
	explicit Vector();
	explicit Vector( const Vector& vector );
	explicit Vector( Vector&& vector );
	explicit Vector( size_t size );
	~Vector() { delete[] m_arr; m_size = m_capacity = 0; m_arr = nullptr; };

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

private:
	T* m_arr;
	size_t m_size;
	size_t m_capacity;
	void new_allocation();
};

#endif

