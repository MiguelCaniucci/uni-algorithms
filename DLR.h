#ifndef DLR_H
#define DLR_H

#include <iostream>
#include <stdlib.h>

template<typename Key>
class DLR{

private:

    struct Node{

        Key key;
        Node* next;
        Node* prev;
    
    };

    int length;
    Node* start;

public:

    DLR();
    ~DLR();

    void print();
    void clear();
    bool isEmpty() const;
    int size();
    
    void pushFront(Key k);
    void pushBack(Key k);
    bool pushAfter(Key k, Key nkey);
    bool pushBefore(Key k, Key nkey);

    bool popFront();
    bool popBack();
    bool popByKey(const Key& k);
    
    DLR<Key>(const DLR<Key> &givenRing);
    DLR<Key> &operator=(const DLR<Key> &rhs);
	bool operator==(const DLR<Key> &rhs);
	bool operator!=(const DLR<Key> &rhs);

    class Iterator{

    private:

        friend class DLR;
        Node* iter;

    public:
        Iterator():iter(NULL){};
        Iterator(Node* ptr){iter = ptr;};
        ~Iterator(){};

        Iterator& operator++() {
            iter = iter->next;
            return *this;
        }

        Iterator& operator--() {
            iter = iter->prev;
            return *this;
        }

        bool operator==(const Iterator& rhs) const{
            return (iter == rhs.iter);
        }

        bool operator!=(const Iterator& rhs) const{
            return (iter != rhs.iter);
        }

        Key operator*(){
            return iter->key;
        }

        Iterator& operator=(const Iterator &rhs) {
                this->iter = rhs.iter;
                return *this;
        }

        Key& getKey() {
            return this->iter->key;
        }

        const Key& getKey() const {
            return this->iter->key;
        }

        Iterator operator++(int) {
            Iterator iter_temp = *this;
            this->iter = this->iter->next;
        return iter_temp;
        }

        Iterator operator--(int) {
            Iterator iter_temp = *this;
            this->iter = this->iter->prev;
        return iter_temp;
        }


    };

    Iterator begin() const{ 
        return Iterator(start);
    }
    
    Iterator end() const{ 
        return Iterator(start->prev);
    }

    void splitClockwise(DLR<Key>::Iterator &it, int len);
    void splitCounterClockwise(DLR<Key>::Iterator &it, int len);

};

//DLR METHODS

template <typename Key>
DLR<Key>::DLR(){
    start = NULL;
    length = 0;
}

template <typename Key>
DLR<Key>::~DLR(){
    this->clear();
}

template<typename Key>
DLR<Key>::DLR(const DLR<Key> &givenRing) {
		*this = givenRing;
}

template <typename Key>
void DLR<Key>::print(){

    if(length == 0){
        std::cout<<"list is empty"<<std::endl;
    }
    Node* node = start;
    for(int i = 0;i<length;i++){
        std::cout << node->key << "   ";
        node = node->next;
    }
    std::cout << std::endl << std::endl;

}

template <typename Key>
void DLR<Key>::pushFront(Key k){

    Node* node = new Node;
    node->key = k;
    
    if(this->isEmpty()){
        node->next = node;
        node->prev = node;
        this->start = node;
        
        length++;
    }else{
        Node* last = start->prev;

        start->prev = node;
        node->next = start;
        node->prev = last;

        this->start = node;
        length++;

    }
}

template <typename Key>
void DLR<Key>::pushBack(Key k){

    Node* node = new Node;
    node->key = k;
    
    if(this->isEmpty()){
        node->next = node;
        node->prev = node;
       
        this->start = node;
       
        length++;

    }else{
        Node* last = start->prev;
      
        node->next = start;
        node->prev = start->prev;
      
        last->next = node;
        start->prev = node;
       
        length++;
    }
}

template<typename Key>
bool DLR<Key>::popFront(){

    if(start==NULL){
        return false;
    }else{  
        Node* last = start->prev;
        Node* temp = start;
        start = start->next;
        start->prev = last;
        last->next = start;
        delete temp;
        length--;
        return true;
    }

}

template<typename Key>
bool DLR<Key>::popBack(){
    
    if(start==NULL){
        return false;
    }else{

        Node* one_before_last = start->prev->prev;
        Node* last = start->prev;
        one_before_last->next = start;
        start->prev = one_before_last;
        delete last;
        length--;
        return true;
    }

}
//DOES NOT WORK PROPERLY FOR TOO MANY APPERENCES !!!
template<typename Key>
bool DLR<Key>::popByKey(const Key& k){

    bool wasDeleted = false;
    Node* curr = start;
    int l = length;
    for(int i = 0;i<l;i++){
        if(curr->key == k){
          
            //first element case
            if(curr==start){
                popFront();
                wasDeleted=true;
                curr = curr->next;

            //last element case
            }else if(curr==start->prev){
                popBack();
                wasDeleted=true;
                curr = curr->next;
           
            //middle element case
            }else{
                Node* temp = curr;
                curr = curr->next;
                Node* prev = temp->prev;
                Node* next = temp->next;

                prev->next = next;
                next->prev = prev;
                
                delete temp;
                wasDeleted=true;
                length--;
            }
        }else{
            //going through the list
            curr = curr->next;
        }
    }
    return wasDeleted;
}

template <typename Key>
bool DLR<Key>::pushAfter(Key k, Key nkey){

    Node* curr = start;
    int l = length;
    for(int i = 0; i<l ;i++){
        if(curr->key == k){

            //last element case
            if(curr==start->prev){
                pushBack(nkey);
                return true;

            //middle element case
            }else{
                Node* node = new Node;
                node->key = nkey;
                node->next = curr->next;
                node->prev = curr;

                curr->next->prev = node;
                curr->next = node;

                length++;
                return true;
            }
        }else{
            //going through the list
            curr = curr->next;
        }
    }
    return false;

}

template <typename Key>
bool DLR<Key>::pushBefore(Key k, Key nkey){

    Node* curr = start;
    for(int i = 0;i<length;i++){
        if(curr->key == k){

            //first element case
            if(curr==start){
                pushFront(nkey);
                return true;

            //middle element case
            }else{
                Node* node = new Node;
                node->key = nkey;
                node->next = curr;
                node->prev = curr->prev;

                Node* prev = curr->prev;
                prev->next = node;
                curr->prev = node;
                
                length++;
                return true;
            }
        }else{
            //going through the list
            curr = curr->next;
        }
    }
    return false;
}

template <typename Key>
bool DLR<Key>::isEmpty() const{
    if(start==NULL)
        return true;
    else
        return false;
}

template <typename Key>
int DLR<Key>::size(){
        return length; 
}

template <typename Key>
void DLR<Key>::clear(){
    int l = length;
    for(int i = 0 ; i < l ; i++){
        popBack();
    }
}

template <typename Key>
DLR<Key>& DLR<Key>::operator=(const DLR<Key> &rhs){

    this->clear();
    Node* curr = rhs.start;
    while(this->length!=rhs.length){
        this->pushBack(curr->key);
        curr = curr->next;
    }
    return *this;
}

template <typename Key>
bool DLR<Key>::operator==(const DLR<Key> &rhs){

    if(this->length != rhs.length) {
			return false;
	}else if (this->length == 0 && rhs.length == 0) {
			return true;
	}

    Node* rhs_node = rhs.start;
    Node* lhs_node = this->start;
    
    for(int i = 0; i < length; i++){
        if(lhs_node->key!=rhs_node->key)
            return false;

        rhs_node = rhs_node->next;
        lhs_node = lhs_node->next;
    }
    return true;
}

template <typename Key>
bool DLR<Key>::operator!=(const DLR<Key> &rhs){
    return !(*this == rhs);
}

//FUNCTIONS

template <typename Key>
void split(const DLR<Key> &source, DLR<Key> &result1, bool dir1, int len1, DLR<Key> &result2, bool dir2, int len2) {
    if (source.isEmpty() == false) {
    typename DLR<Key>::Iterator it1 = source.begin();
    typename DLR<Key>::Iterator it2 = ++source.begin();
    
    result1.clear();
    result2.clear();

    if (dir1)
        result1.splitClockwise(it1, len1);
    else
        result1.splitCounterClockwise(it1, len1);

    if (dir2)
        result2.splitClockwise(it2, len2);
    else 
        result2.splitCounterClockwise(it2, len2);
    }
}


template <typename Key>
void DLR<Key>::splitClockwise(DLR<Key>::Iterator &it, int len) {
    int count = 0;

    while (count < len) {
        pushBack(*it);
        it--;
        it--;
        count++;
    }
}


template <typename Key>
void DLR<Key>::splitCounterClockwise(DLR<Key>::Iterator &it, int len) {
    int count = 0;

    while (count < len) {
        pushFront(*it);
        it--;
        it--;
        count++;
    }
}

#endif