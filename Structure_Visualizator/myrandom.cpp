#include "myrandom.h"

MyRandom::MyRandom()
{
}

template<class ForwardIterator>
void MyRandom::fillRange(ForwardIterator begin, ForwardIterator end)
{
    std::generate(begin, end, [=]() { return this->bounded(-500,500);});
}
