#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
#include "data.h"

const int DEFAULT_QUEUE_LENGTH = 5;

class queue
{
	/* --- friends --- */
	friend std::ostream &operator<<(std::ostream &stream, const queue &queue);
	
	/* --- private members --- */
	private: int max;
	private: int head;
	private: int tail;
	private: data** items;
	
	/* --- private methods --- */
	private: void print(std::ostream &stream = std::cout) const;
	private: void incr(int &i) const;
	private: void copy_items(data** source, int begin, int end);
	
	/* --- constructors --- */
	public: explicit queue(int max = DEFAULT_QUEUE_LENGTH); // explicit prevents conversion by construction
	/* --- copy constructor --- */
	public: queue(const queue &copy);
	/* --- destructor --- */
	public: ~queue();
	
	public: void operator=(const queue &q);
	
	/* --- public methods --- */
	public: void enqueue(data* item);
	public: data* dequeue();
	public: bool is_empty() const;
	public: bool is_full() const;
};

#endif