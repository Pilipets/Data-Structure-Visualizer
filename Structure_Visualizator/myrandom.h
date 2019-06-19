#ifndef MYRANDOM_H
#define MYRANDOM_H
#include <QRandomGenerator>

class MyRandom : public QRandomGenerator{
public:
    MyRandom();
    template<class ForwardIterator>
    void fillRange(ForwardIterator begin, ForwardIterator end);
private:
};

#endif // MYRANDOM_H
