#ifndef WHATEVER_HPP
# define WHATEVER_HPP

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

template<typename T>
void	swap(T &t, T &u)
{
	T	tmp = t;
	
	t = u;
	u = tmp;
	return ;
}

template<typename T>
T		&min(T &t, T &u)
{
	if (t < u)
		return (t);
	else
		return (u);
}


template<typename T>
T		&max(T &t, T &u)
{
	if (t > u)
		return (t);
	else
		return (u);
}


#endif
