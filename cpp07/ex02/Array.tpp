template<typename T>
Array<T>::Array():elem(NULL),sz(0){}

template<typename T>
Array<T>::~Array() {delete[] elem;}


template<typename T>
unsigned int Array<T>::size() const {return sz;}

template<typename T>
Array<T>::Array(unsigned int s)
{
	elem = new T[s];
	sz =s;
}

template<typename T>
Array<T>::Array(const Array &rhs):elem(new T[rhs.sz]), sz(rhs.sz)
{
	for (unsigned int i = 0; i < sz; ++i)
		elem[i] = rhs.elem[i];
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array &rhs)
{
	T *tmp = new T[rhs.sz];
	for (unsigned int i = 0; i < rhs.sz; ++i)
		tmp[i] = rhs.elem[i];
	delete[] elem;
	elem = tmp;
	sz = rhs.sz;
	return (*this);
}

template<typename T>
T	&Array<T>::operator[](unsigned int i)
{
	if (i >= size() || elem == NULL)
		throw(invalidIndex());
	else
		return (elem[i]);
}



template<typename T>
const T	&Array<T>::operator[](unsigned int i) const
{
	if (i >= size() || elem == NULL)
		throw(invalidIndex());
	else
	return (elem[i]);
}
