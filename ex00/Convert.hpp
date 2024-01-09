#ifndef CONVERT_HPP
# define CONVERT_HPP
# include <iostream>
# include <cstring>
# include <cstdlib>
# include <limits.h>
# include <cmath>

class	ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter &operator=(ScalarConverter const &rhs);
		~ScalarConverter();
	public:
		static int		whatType(std::string nbr);
		static int		checkPrintChar(std::string nbr);
		static int		checkInt(std::string nbrr);
		static int		checkFloat(std::string nbr);
		static int		checkDouble(std::string nbr);
		static int		checkException(std::string nbr);

		static void		isChar(char *str);
		static void		isInt(char *str);
		static void		isFloat(char *str);
		static void		isDouble(char *str);

		static void		affChar(double nbr);
		static void		affInt(double nbr);
		static void		affDouble(double nbr);
		static void		affFloat(double nbr);
		static void		exception(char *str);
};

#endif