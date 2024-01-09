#include "Convert.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	return (*this);
}

int	ScalarConverter::whatType(std::string nbr)
{
	if (nbr.length() == 1 && checkPrintChar(nbr))
	{
		return (0);
	}
	if (checkInt(nbr)){
		return (1);
	}
	if (checkDouble(nbr)){
		return (2);
	}
	if (checkFloat(nbr)){
		return (3);
	}
	return (4);
}

int ScalarConverter::checkFloat(std::string nbr)
{
	int i = 0;
	int j = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i])
	{
		if ((nbr[i] < '0' || nbr[i] > '9') && nbr[i] != '.'){
			if (nbr[i] == 'f' && nbr[i + 1] == '\0' && j <= 1)
				return (1);
			else
				return (0);
		}
		if (nbr[i] == '.')
			j++;
		i++;
	}
	if (j > 1)
		return (0);
	return (1);
}

int	ScalarConverter::checkDouble(std::string nbr)
{
	int i = 0;
	int j = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i])
	{
		if ((nbr[i] < '0' || nbr[i] > '9') && nbr[i] != '.')
			return (0);
		if (nbr[i] == '.')
			j++;
		i++;
	}
	if (j > 1)
		return (0);
	return (1);
}

int	ScalarConverter::checkInt(std::string nbr)
{
	int	i = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i]){
		if (nbr[i] < '0' || nbr[i] > '9')
			return (0);
		i++;
	}
	if (std::strtod(nbr.c_str(), NULL) > 2147483647 || std::strtod(nbr.c_str(), NULL) < -2147483648)
		return (0);
	return (1);
}

int	ScalarConverter::checkPrintChar(std::string nbr)
{
	if ((nbr[0] > 32 && nbr[0] <  47) || (nbr[0] > 57 && nbr[0] < 127))
		return (1);
	return (0);
}

void	ScalarConverter::affChar(double nbr)
{
	if (nbr < 0 || nbr > 127 || nbr != nbr)
		std::cout << "char: impossible" << std::endl;
	else if (nbr < 32 || nbr > 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '"<< static_cast<char>(nbr) << "'" << std::endl;
}

void	ScalarConverter::affInt(double nbr)
{
	if (nbr > 2147483647 || nbr < -2147483648 || nbr != nbr)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: "<< static_cast<int>(nbr) << std::endl; 
}

void	ScalarConverter::affDouble(double nbr)
{
	std::cout << "double: " << nbr << std::endl;
}

void	ScalarConverter::affFloat(double nbr)
{
	std::cout << "float: "<< static_cast<float>(nbr) << "f" << std::endl;
}

void	ScalarConverter::isChar(char* str)
{
	std::cout << "char: " << str[0] << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl; 
	std::cout << "float: " << static_cast<float>(str[0]) << "f" << std::endl; 
	std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
}

void	ScalarConverter::isInt(char* str)
{
	int	i = std::atoi(str);
	
	affChar(static_cast<double>(i));
	std::cout << "int: " << i << std::endl;
	affFloat(static_cast<double>(i));
	affDouble(static_cast<double>(i));
}

void	ScalarConverter::isFloat(char* str)
{
	float	i = std::atof(str);
	
	affChar(static_cast<double>(i));
	affInt(static_cast<double>(i));
	std::cout << "float: "<< i << "f" << std::endl;
	std::cout << "double: "<< i << std::endl;
}

void	ScalarConverter::isDouble(char* str)
{
	double i = strtod(str, NULL);
	affChar(i);
	affInt(i);
	affFloat(i);
	affDouble(i);
}

void	ScalarConverter::exception(char* str)
{
	std::string	tab[6] = {"-inff", "+inff", "-inf", "+inf", "nan", "nanf"};
	void		(*functptr[])(char *str) = {&isFloat, &isFloat, &isDouble, &isDouble, &isDouble, &isFloat};
	for (int i = 0; i < 6; i++){
		if (!tab[i].compare(str)){
			(*functptr[i])(str);
			return;
			}
	}
	std::cout << str << " is a wrong argument" << std::endl;
}