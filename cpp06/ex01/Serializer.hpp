
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

#ifndef DEBUG
#define DEBUG 0
#endif

typedef struct
{
	std::string	name;
	int			age;
	std::string	email;
} Data;

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &copy);
	public:
		Serializer &operator=(const Serializer &copy);
		~Serializer(void);

	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif /* SERIALIZER_HPP */
