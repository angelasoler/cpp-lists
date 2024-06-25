#include "Serializer.hpp"

void	printPerson(Data person)
{
	std::cout << "name: "<< person.name << std::endl;
	std::cout << "age: "<< person.age << std::endl;
	std::cout << "email: "<< person.email << std::endl;
}


int	main()
{
	Data		person;
	uintptr_t	raw;
	Data		*deserializedPerson;

	person.name = "Angela";
	person.age = 34;
	person.email = "angela@email.com";


	std::cout<< "\t\t======= person ======" << std::endl;
	printPerson(person);
	raw = Serializer::serialize(&person);
	std::cout<< "Raw: " << raw << std::endl;
	std::cout<< "Person Address: " << &person << std::endl;
	deserializedPerson =  Serializer::deserialize(raw);
	std::cout<< "\t\t======= deserialized ======" << std::endl;
	printPerson(*deserializedPerson);
	std::cout<< "Deserialized Address: " << deserializedPerson << std::endl;
}
