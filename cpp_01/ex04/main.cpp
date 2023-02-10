#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

//https://stackoverflow.com/questions/2390912/checking-for-an-empty-file-in-c
bool	is_empty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

bool	test(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "error Nb arg invalid" << std::endl;
		return (false);
	}
	std::ifstream file_1(argv[1]);
	if (!file_1)
	{
		std::cerr << "error file does not exits " << std::endl;
		file_1.close();
		return (false);
	}
	if (is_empty(file_1))
	{
		std::cerr << "error empty file" << std::endl;
		file_1.close();
		return (false);
	}
	return (true);
}

void	replace(std::ifstream& file_1, std::ofstream& file_2, std::string& read, const std::string s1, const std::string s2 )
{
//	while (std::getline(file_1, read))
	
	(void)file_1;

		size_t pos = read.find(s1);
		if ( pos == std::string::npos)
		{
			file_2 << read << std::endl;
		}
		else
		{
			while(read.length())
			{
				pos = read.find(s1);
				file_2 << read.substr(0, pos);
				if (pos != std::string::npos )
				{
					file_2 << s2;	
					read = read.substr(pos + s1.length(), std::string::npos);
				}
				else
				{
					read = "";
				}
			}
		file_2 << std::endl;
		}
}


int	main(int argc, char *argv[])
{
	std::string	file_extension = ".replace";
	std::ifstream file_1(argv[1]);
	if (test(argc, argv))
	{
		const std::string	s1 = argv[2];
		std::string 		f_name= argv[1];
		const std::string	s2 = argv[3];
		std::ifstream file_1(argv[1]);
		std::ofstream file_2;
		f_name.append(".replace");
		file_2.open(f_name.data());
		if (!file_2)
		{
			std::cerr << "error writing file " << std::endl;
			file_2.close();
			return (-1);
		}
		std::string	read;
		while (std::getline(file_1, read))
		{
			replace(file_1, file_2, read, s1, s2);
		}
		file_1.close();
		file_2.close();
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
	
}
