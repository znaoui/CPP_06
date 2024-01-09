#include "Serializer.hpp"

int	main ( void )
{
	Data		data;
	Data		*ptr_data;
	uintptr_t	objetif_1;

	data.name = "hello\n";
	data.nb = 1;

	objetif_1 = Serializer::serialize(&data);
	ptr_data = Serializer::deserialize(objetif_1);

	std::cout << "\033[1;31m-------------------- Serial ----------------------------------\033[0m" << std::endl;
	std::cout << "Adress serial : " << objetif_1 << std::endl;

	std::cout << "\033[1;31m-------------------- Data before serial -----------------------\033[0m" << std::endl;
	std::cout << "Adress : " << &ptr_data << std::endl;
	std::cout << "Name : " << data.name;
	std::cout << "Nb : " << data.nb << std::endl;

	std::cout << "\033[1;31m-------------------  Data after serial ------------------------\033[0m" << std::endl;
	std::cout << "Adress : " << ptr_data << std::endl;
	std::cout << "Name : " << ptr_data->name;
	std::cout << "Nb : " << ptr_data->nb << std::endl;
}
