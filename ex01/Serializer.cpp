#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::~Serializer()
{

}

Serializer::Serializer(Serializer const &src)
{
	*this = src;
}

Serializer &Serializer::operator=(Serializer const &src)
{
	return (*this);
}

// Elle prend un pointeur et convertit celui-ci vers le type d’entier non-signé uintptr_t.
uintptr_t	Serializer::serialize(Data * ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

// Elle prend un entier non-signé en paramètre et le convertit en pointeur sur Data.
Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}