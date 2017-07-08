#include "data.h"

data::data(const std::string &value) : value(value)
{
}

std::ostream &operator<<(std::ostream &stream, const data &item)
{
	return stream << item.value << std::flush;
}