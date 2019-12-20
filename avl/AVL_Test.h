#include <iostream>
#include <stdlib.h>
#include "Dictionary.h"

void testInsertion(){

    std::cout << "**********************" << std::endl;
    std::cout << "****INSERTION TEST****" << std::endl;
    std::cout << "**********************" << std::endl << std::endl;

    Dictionary<int, int> avl;
    
    std::cout << "Inserting: 10, 13, 5, 17, 8, 21, 9" << std::endl << std::endl;

    avl.insert(10,10);
    avl.insert(13,13);
    avl.insert(5,5);
    avl.insert(17,17);
    avl.insert(8,8);
    avl.insert(21,21);
    avl.insert(9,9);
    
    avl.printInfo();
    
    avl.publicPrintPrettyTree();

    std::cout << "Inserting: 8, 7, 23" << std::endl << std::endl;
    avl.insert(8,8); //doesn't add, key is unique
    avl.insert(7,3);
    avl.insert(23,5);

    avl.printInfo();

    avl.publicPrintPrettyTree();

    std::cout << "**********************" << std::endl;
    std::cout << "*******END TEST*******" << std::endl;
    std::cout << "**********************" << std::endl << std::endl;

}

void testDeleting(){

    std::cout << "**********************" << std::endl;
    std::cout << "****DELETING TEST*****" << std::endl;
    std::cout << "**********************" << std::endl << std::endl;

    Dictionary<int, int> avl;
    
    std::cout << "Inserting: 8, 2, 6, 35, 65, 11, 0, 121, 1" << std::endl << std::endl;

    avl.insert(8,10);
    avl.insert(2,13);
    avl.insert(6,5);
    avl.insert(35,17);
    avl.insert(65,8);
    avl.insert(11,21);
    avl.insert(0,9);
    avl.insert(121,21);
    avl.insert(1,9);
    
    avl.printInfo();
    
    avl.display();
    std::cout << "Delete 35" << std::endl;
    avl.erease(35);//two children case
    avl.display();
    std::cout << "Delete 121" << std::endl;
    avl.erease(121);//no children case
    avl.display();
    std::cout << "Delete 0" << std::endl;
    avl.erease(0);//one child case
    avl.display();
    avl.printInfo();

    std::cout << "**********************" << std::endl;
    std::cout << "*******END TEST*******" << std::endl;
    std::cout << "**********************" << std::endl << std::endl;


}

void testCopying(){

    std::cout << "**********************" << std::endl;
    std::cout << "*****COPYING TEST*****" << std::endl;
    std::cout << "**********************" << std::endl << std::endl;

    Dictionary<int, int> avl;
    
    std::cout << "Inserting: 1, 3, 5, 0, 4, 9" << std::endl << std::endl;

    avl.insert(1,10);
    avl.insert(3,13);
    avl.insert(5,5);
    avl.insert(0,17);
    avl.insert(4,8);
    avl.insert(9,21);

    Dictionary<int, int> copy(avl);
    Dictionary<int, int> opEqual;

    opEqual = avl;

    avl.display();
    copy.display();
    opEqual.display();

    std::cout << "**********************" << std::endl;
    std::cout << "*******END TEST*******" << std::endl;
    std::cout << "**********************" << std::endl << std::endl;

}

void testDisplay(){

    std::cout << "**********************" << std::endl;
    std::cout << "*****DISPLAY TEST*****" << std::endl;
    std::cout << "**********************" << std::endl << std::endl;
    
    Dictionary<int, int> avl;
    avl.display(); //empty tree
    avl.print(ascending);
    avl.print(descending);
    std::cout << "Inserting: 1, 5, 3, 2, 7, 0" << std::endl << std::endl;
    avl.insert(1,1);
    avl.insert(5,2);
    avl.insert(3,5);
    avl.insert(2,3);
    avl.insert(7,6);
    avl.insert(0,12);
    avl.display(); 
    avl.print(ascending);
    avl.print(descending);
        

    avl.display();

    std::cout << "**********************" << std::endl;
    std::cout << "*******END TEST*******" << std::endl;
    std::cout << "**********************" << std::endl << std::endl;
}

void findingKeyInfoTest(){

    std::cout << "**********************" << std::endl;
    std::cout << "***FINDING KEY TEST***" << std::endl;
    std::cout << "**********************" << std::endl << std::endl;

    Dictionary<int, int> avl;

    avl.insert(1,7);
    avl.insert(2,8);
    avl.insert(3,9);
    avl.insert(4,10);
    avl.insert(5,11);
    avl.insert(6,12);
    avl.printInfo();
    avl.display();

    for(int i = 0, n; i < 10; i++){
        n = rand()%10;
        if(avl.search(n))
            std::cout << "Key = " << n << " found in the tree" << std::endl;
        else    
            std::cout << "Key = " << n << " not found" << std::endl;

        std::cout << std::endl;
    }

    //catching exception if there is no node with the given key
    try{
    std::cout << avl.getInfo(7) << std::endl;
    }catch(...){
        std::cerr << "No such key" << std::endl;
    }   

    try{
    std::cout << "Key = 7 -> Info = " <<avl.getInfo(2) << std::endl;
    std::cout << "Key = 4 -> Info = " <<avl.getInfo(4) << std::endl;
    std::cout << "Key = 6 -> Info = " <<avl.getInfo(6) << std::endl;
    }catch(...){
        std::cerr << "No such key" << std::endl;
    }



    std::cout << "**********************" << std::endl;
    std::cout << "*******END TEST*******" << std::endl;
    std::cout << "**********************" << std::endl << std::endl;
}


