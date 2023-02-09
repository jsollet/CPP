#ifndef HARL_HPP
# define HARL_HPP

class Harl
{
	public:
		Harl();
		Harl(size_t intensity);
		~Harl();
		void complain(std::string level);
		void escalate(std::string level);
	private:
		size_t		intensity;
		typedef void (Harl::*fp)();
		std::string	level;
		void debug (void);
		void info (void);
		void warning (void);
		void error (void);
		void unknow (void); // pour autres parametres passes.
};

#endif // HARL_HPP
