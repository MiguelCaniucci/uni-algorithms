#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Sequence.h"


void testCopyConstr(){

    Sequence<int, int> seq;
    
    seq.pushBack(1,1);
    seq.pushBack(2,2);
    seq.pushBack(3,3);
    seq.pushBack(4,4);
    seq.pushBack(5,5);

    Sequence<int, int> copy(seq);
    
    seq.print();
    copy.print();

}
void testPlusConstr(){

    Sequence<double, std::string> seq;
    seq.pushBack(1.1, "a");
    seq.pushBack(2.2, "b");
    seq.pushBack(3.3, "c");
    seq.pushBack(4.4, "d");
    seq.pushBack(5.5, "e");

    Sequence<double, std::string> seq1;
    seq1.pushBack(1.2, "f");
    seq1.pushBack(2.3, "g");
    seq1.pushBack(3.4, "h");
    seq1.pushBack(4.5, "i");
    seq1.pushBack(5.6, "j");

    seq = seq + seq1;
    seq.print();

}
void testProduce(){

    Sequence<double, std::string> seq;
    seq.pushBack(1.1, "a");
    seq.pushBack(2.2, "b");
    seq.pushBack(3.3, "c");
    seq.pushBack(4.4, "d");
    seq.pushBack(5.5, "e");

    Sequence<double, std::string> seq1;
    seq1.pushBack(11.1, "f");
    seq1.pushBack(22.2, "g");
    seq1.pushBack(33.3, "h");
    seq1.pushBack(44.4, "i");
    seq1.pushBack(55.5, "j");

    Sequence<double, std::string> seq2;

    Sequence<double, std::string> prod = produce(seq, 1, 2, seq1, 10, 1, 17); //no such position
    prod.print(); 
    Sequence<double, std::string> prod1 = produce(seq, 2, 4, seq1, 1, 3, -2); //negative limit
    prod1.print();
    Sequence<double, std::string> prod2 = produce(seq, 1, 2, seq1, 1, 1, 0); //zero limit
    prod2.print();
    Sequence<double, std::string> prod3 = produce(seq, 1, 2, seq2, 1, 1, 17); //one list is empty
    prod3.print();
    Sequence<double, std::string> prod4 = produce(seq, 0, 3, seq1, 2, 4, 11); //works 
    prod4.print(); 

}
void testRemove(){
    int i = 0;
    Sequence<std::string, int> seq;
    Sequence<double, char> seq1;

    seq.pushBack("c", 4);
    seq.pushBack("w", 5);
    seq.pushBack("g", 1);
    seq.pushBack("z", 7);
    seq.pushBack("j", 3);
    seq.pushBack("l", 8);

    if(seq.getFromPosition(-2)==NULL)
        i++; //returns NULL
    if(seq.getFromPosition(10)==NULL)
        i++; //returns NULL
    if(seq.getFromPosition(3)==NULL)
        i++;; //returns node
    
    if(i==2)
        std::cout << "test passed" << std::endl;
    else
        std::cout << "test failed" << std::endl;

    seq.popBack();
    seq.popFront();
    seq.ereaseByInfo(3);
    seq.ereaseByKey("g");
    seq.print();
    seq.removeAll(); //removing all elements
    seq1.removeAll(); //removing from empty list
    seq.print();
    seq1.print();

}
void testAdding(){

    Sequence<std::string, int> seq;

    seq.pushBack("c", 4);
    seq.pushBack("w", 5);
    seq.pushBack("g", 1);
    seq.pushBack("z", 7);
    seq.pushBack("j", 3);
    seq.pushBack("l", 8);

    seq.print();
    seq.pushAfter(2, "k", 3); //adds element after second element 
    seq.pushAfter(10, "r", 4); //no such position
    seq.pushBack("b", 9); //last
    seq.pushFront("x", 2); //first
    seq.print();

}

int main(){

    testCopyConstr();
    testPlusConstr();
    testProduce();
    testAdding();
    testRemove();
  
    return 0;
}