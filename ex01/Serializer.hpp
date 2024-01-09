#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

typedef struct s_data
{
	std::string     name;
	int             nb;

}	Data;

class	Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &src);
		Serializer &operator=(Serializer const &src);
		~Serializer();
	public:
		static uintptr_t	serialize(Data * ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
