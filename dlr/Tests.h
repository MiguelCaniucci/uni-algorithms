#include <iostream>
#include <stdlib.h>

#include "DLR.h"

void testPopping(){

    DLR<int> ring;
    //deleting from empty list
    ring.popByKey(3);
    ring.popFront();
    ring.popBack();
    //adding elements
    ring.pushFront(1);
    ring.pushFront(2);
    ring.pushFront(3);
    ring.pushFront(4);
    ring.pushFront(5);
    ring.pushFront(6);
    ring.pushFront(7);
    ring.pushFront(8);
    ring.pushFront(9);
    ring.print();
    //deleting 
    ring.popFront();
    ring.popBack();
    ring.popByKey(5);
    //deleting non-existing key 
    ring.popByKey(-3);
    //printing
    ring.print();

}

void testPushing(){
    
    DLR<int> ring;
    ring.pushFront(1);
    ring.pushFront(2);
    ring.pushFront(3);
    ring.pushFront(4);
    ring.pushFront(5);
    ring.pushFront(6);
    ring.pushFront(7);
    ring.print();
    ring.pushBack(8);
    ring.print();
    ring.pushAfter(5,10);
    ring.print();
    ring.pushBefore(8,20);
    ring.print();
}


void testOperators(){
    
    DLR<double> ring;
    ring.pushBack(1.1);
    ring.pushBack(2.2);
    ring.pushBack(3.3);
    ring.pushBack(4.4);
    ring.pushBack(5.5);
    ring.pushBack(6.6);
    ring.pushBack(7.7);
    DLR<double> other_ring;

    other_ring = ring;
    other_ring.print();
    ring.print();

    if(ring==other_ring)
        std::cout<<"same rings"<<std::endl;

    ring.popBack();

    if(ring!=other_ring)
        std::cout<<"different rings"<<std::endl;

}

void testSplit(){

    

}

void testIterator(){

    DLR<int> ring;
    ring.pushBack(1);
    ring.pushBack(2);
    ring.pushBack(3);
    ring.pushBack(4);
    ring.pushBack(5);
    ring.pushBack(6);

    DLR<int>::Iterator it;
    it = ring.begin();
    while(it!=ring.end()){
        std::cout<<it.getKey()<<std::endl;
        ++it;
    }

}

