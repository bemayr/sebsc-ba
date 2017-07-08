#include <iostream>
#include <cstdlib>
#include <cassert>
#include "queue.h"

using std::cout;

queue::queue(int max)
{
	cout << "queue::queue(" << max << ")" << std::endl;
	this->max = max + 1;
	this->head = this->tail = 0;
	this->items = new data*[this->max]; // *items vs. data*
}

queue::queue(const queue &copy)
{
	cout << "queue::copy-queue(" << copy.max - 1 << ")" << std::endl;
	this->max = copy.max;
	this->head = copy.head;
	this->tail = copy.tail;
	this->items = new data*[copy.max];
	copy_items(copy.items, copy.head, copy.tail);
}

queue::~queue()
{
	cout << "queue::~queue()" << std::endl;
	delete [] items;
}

void queue::operator=(const queue &q)
{
	if(this != &q)
	{
		this->max = q.max;
		this->head = q.head;
		this->tail = q.tail;
		delete this->items;
		this->items = new data*[q.max];
		copy_items(q.items, q.head, q.tail);
	}
}

void queue::incr(int &i) const
{
	i = (i + 1) % this->max;
}

void queue::copy_items(data** source, int begin, int end)
{
	for(int i = begin; i != end; incr(i))
	{
		this->items[i] = source[i];
	}
}

void queue::print(std::ostream &stream) const
{
	stream << "[";

	for(int i = this->head; i != this->tail; incr(i))
	{
		if(i != head)
		{
			stream << ", ";
		}
		
		stream << *this->items[i]; // because of **data, items[i] is a pointer to a data-element
	}

	stream << "]" << std::flush;
}

std::ostream &operator<<(std::ostream &stream, const queue &queue)
{
	queue.print(stream);
	return stream;
}

/* --- public methods --- */
void queue::enqueue(data* item)
{
	assert(!is_full());
	this->items[this->tail] = item;
	incr(this->tail);
}

data* queue::dequeue()
{
	assert(!is_empty());
	data* item = items[head];
	incr(this->head);
	return item;
}

bool queue::is_empty() const
{
	return this->head == this->tail;
}

bool queue::is_full() const
{
	return (this->tail + 1) % this->max == this->head;
}
