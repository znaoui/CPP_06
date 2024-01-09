#include "Convert.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "\033[1;31m Error: \033[m The number of arguments is incorrect !" << std::endl;
        std::cout << "         Correct using: \"./Convert value1\"" << std::endl;
		return (1);
	}
	char*	str = argv[1];
	void	(*functptr[])(char *str) = {&ScalarConverter::isChar, &ScalarConverter::isInt, &ScalarConverter::isDouble, &ScalarConverter::isFloat, &ScalarConverter::exception};
	int		i = ScalarConverter::whatType(str);
	(*functptr[i])(str);
	return 0;
}