//lang::CwC

#include "queue.h"
#include <stdio.h>

// test equal and hash
void Test5() {    bool result = true;
    StrQueue* q1 = new StrQueue(5);
    StrQueue* q2 = new StrQueue(4);

    String* o = new String("hello");
    String* o2 = new String("goodbye");

    q1->enqueue(o);
    q2->enqueue(o);

    result &= (q1->equals(q2));
    result &= (q1->hash() == q2->hash());

    q2->enqueue(o2);

    result &= (!q1->equals(q2));
    result &= (q1->hash() != q2->hash());
/*
    q1->clear();
    q2->clear();

    q1->enqueue(o);
    q2->enqueue(o2);

    result &= (!q1->equals(q2));
    result &= (q1->hash() != q2->hash());

    printf("%d\n", result);

    delete q1;
    delete q2;
    delete o;
    delete o2;
    */
   std::cout << "expected result: 1\nactual result:   " << result << "\n";
    if (result) {
        exit(0);
    }
    exit(4);
}

int main(int argc, char** argv)
{
    Test5();
}