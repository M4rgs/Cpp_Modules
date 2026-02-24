#include "Serializer.hpp"

int main()
{
    Data *p = new Data();

    p->number = 1337;
    p->name = "TAHA";

    uintptr_t o = Serializer::serialize(p);
    Data *t = Serializer::deserialize(o);

    std::cout << "number : " << t->number << std::endl << "name : " << t->name << std::endl; 
}