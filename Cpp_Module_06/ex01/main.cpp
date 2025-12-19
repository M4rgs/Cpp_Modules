#include "Serializer.hpp"

int main()
{
    Data *p = new Data();
    p->n = 1337;
    p->name = "TAHA";
    uintptr_t o = Serializer::serialize(p);
    Data *t = Serializer::deserialize(o);
    std::cout << "number : " << t->n << std::endl << " name : " << t->name << std::endl; 
}