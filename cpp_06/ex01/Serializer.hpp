#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"

#include <cstdint>

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

class	Serializer
{

	public:

		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
		static Data		*getData();
		~Serializer();

	private:
		Serializer();
		Serializer(const Data &rhs);
		Serializer(const Serializer &rhs);
		Serializer &operator=(const Serializer &rhs);
		static Data			*data;

};


#endif
