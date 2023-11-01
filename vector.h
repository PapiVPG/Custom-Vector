#ifndef VECTOR_H
#define VECTOR_H

template< typename T >
class Vector {
	T* arr;
	size_t m_size;
	size_t m_capacity;
public:
	Vector();
	Vector( Vector& vector );
	Vector( Vector&& vector );
	Vector( size_t size );
	~Vector() { arr = nullptr; m_size = m_capacity = 0; delete []arr; };

	void new_allocation();
	void push_back( T value );
	bool empty();
	size_t size();
	size_t capacity();
	void pop_back();
	void clear();

	T operator[]( size_t index );
	T* begin();
	T* end();
};

#endif

