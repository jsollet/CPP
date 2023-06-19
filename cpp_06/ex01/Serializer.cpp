#include "Serializer.hpp"

Data		*data = NULL;


Serializer::Serializer::~Serializer()
{
	delete ::data;
}

Serializer::Serializer()
{
	::data =  new Data();
}

Serializer::Serializer(Serializer const &rhs)
{
	::data =  new Data();
	::data = rhs.getData();
	
}

Serializer::Serializer(const Data &rhs)
{
	
	::data =  new Data();
	::data->aInt = rhs.aInt;
	::data->aFloat = rhs.aFloat;
	::data->aString = rhs.aString;
}

Serializer &Serializer::operator=(const Serializer &rhs)
{
	if (this != &rhs)
	{
		::data = rhs.getData();
	}
	return (*this);
}

Data	 *Serializer::getData()
{
	return (::data);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
