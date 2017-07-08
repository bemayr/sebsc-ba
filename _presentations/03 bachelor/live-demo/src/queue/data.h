#ifndef _DATA_H
#define _DATA_H

#include <iostream>
#include <string>

class data {
	/* --- friends --- */
	friend std::ostream &operator<<(std::ostream &stream, const data &item);
	
	/* --- private members --- */
	private: std::string value;
	
	/* --- constructor --- */
	public: data(const std::string &value);
};


#endif