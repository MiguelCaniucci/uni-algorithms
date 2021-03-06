#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <stdlib.h>
#include <string.h>

template<typename Key, typename Info>
class Sequence{
    
private:
    struct Node{
        Key key;
        Info info;
        Node* next;
    };
        Node* head;

public:

        Sequence(); 
        ~Sequence(); 
        void pushBack(Node* node); 
        void pushBack(Key k, Info i);  
        void pushAfter(int pos, Key k, Info i);  
        void pushFront(Key k, Info i);  
        void popBack();  
        void popFront(); 
        void ereaseByKey(const Key &k); 
        void ereaseByInfo(const Info &i);  
        int size(); 
        void print();
        Node* getFromPosition(int position); 
        Sequence(const Sequence &s);  
        Sequence<Key, Info>& operator=(Sequence &s);  
        Sequence<Key, Info>& operator+(Sequence &s);  
        void removeAll(); 
        bool isEmpty(); 
        Node* getKey(const Key &k);
        Node* getInfo(const Info &i);

};

template<typename Key, typename Info>
Sequence<Key, Info> produce(const Sequence<Key, Info> &S1, int stat1, int len1, const Sequence<Key, Info> &S2, int stat2, int len2, int limit){

    Sequence<Key, Info> produced;
    Sequence<Key, Info> copy1 = S1;
    Sequence<Key, Info> copy2 = S2;

    if((copy1.isEmpty())==true||(copy2.isEmpty()==true)){  //checks if both have elements
        std::cout << "at least one of the lists is empty" << std::endl;
        
    }else if((stat1>=copy1.size())||(stat2>=copy2.size())||(stat1<0)||(stat2<0)){ //checks positions
        std::cout << "no such position" << std::endl;
    
    }else if(limit<=0){ //checks limit
        std::cout << "negative/zero limit" << std::endl;
    
    }else if(len1<0||len2<0){
        std::cout << "negative length" << std::endl;

    }else{
        
        int i, j, pos1 = stat1, pos2 = stat2;

        while(produced.size()<limit){

            i = 0, j = 0;
            while(i<len1){
                if(produced.size()<limit)
                    produced.pushBack(copy1.getFromPosition(pos1)->key, copy1.getFromPosition(pos1)->info);    //sequence S1 loop
                pos1++, i++;
                if(pos1==copy1.size())
                    pos1=0;
                
            }    

            while(j<len2){
                if(produced.size()<limit)
                    produced.pushBack(copy2.getFromPosition(pos2)->key, copy2.getFromPosition(pos2)->info);   //sequence S2 loop
                pos2++, j++;
                if(pos2==copy2.size())
                    pos2=0;
            
            }
        }
    }
    return produced;

}

        template<typename Key, typename Info>
        Sequence<Key, Info>::Sequence(){ 
            this->head = NULL;
        }
 
        template<typename Key, typename Info>
        Sequence<Key, Info>::~Sequence(){ 
            Node* del = head;
            Node* temp = new Node;
            while(del!=NULL){
                temp = del->next;
                delete del;
                del = temp;
            }
        }
    
        template<typename Key, typename Info>
        void Sequence<Key, Info>::pushBack(Node* node){ 

            if(head==NULL){
                head = node;
            }else{  
                Node* temp = head;
                while(temp->next!=NULL){
                    temp = temp->next;
            }
            temp->next = node;
            }
        }

        template<typename Key, typename Info>
        void Sequence<Key, Info>::pushBack(Key k, Info i){ 
            Node* node = new Node;
            node->key = k;
            node->info = i;
            node->next = NULL;
            pushBack(node);
        }

        template<typename Key, typename Info>
        void Sequence<Key, Info>::pushAfter(int pos, Key k, Info i){ 
            
            Node* node = new Node;
            node->key = k;
            node->info = i;

            if(pos == size()-1){
                
                pushBack(k, i);  
            
            }else if(pos>=size()||pos<0){
                
                std::cout << "no such position" << std::endl; 
            
            }else{
                
            int n = 0;
            Node* curr = head;
            Node* prev = new Node;
            while(n<=pos){              
                prev = curr;
                curr = curr->next;
                n++;
            }
            prev->next = node;      
            node->next = curr;
          }
        }

        template<typename Key, typename Info>
        void Sequence<Key, Info>::pushFront(Key k, Info i){ 

            Node* node = new Node; 
            Node* temp = new Node;
            node->key = k, node->info = i;
            if(node==NULL)
                std::cout << "node is NULL" << std::endl;
            temp = head;
            head = node;
            head->next = temp;
        }

        template<typename Key, typename Info>
        void Sequence<Key, Info>::popBack(){ 
            
            Node *temp = head;
            Node *prev;
            if(head->next==NULL){
                delete head;
                head=NULL;
            }else{
                
                while(temp->next != NULL){
                    prev=temp;
                    temp=temp->next;
                }
            delete prev->next;
            prev->next = NULL; 
          }    

        }

        template<typename Key, typename Info>
        void Sequence<Key, Info>::popFront(){ 

            Node* toDelete = new Node;

            if (head != NULL){
                toDelete = head;
                head = head->next;
                delete toDelete;
            }else{
                std::cout << "empty list" << std::endl;
            }

        }

        template<typename Key, typename Info>
        void Sequence<Key, Info>::ereaseByKey(const Key &k){ 
                
            Node* temp = head;
            Node* prev = NULL;
            Node* del = new Node;
            if(temp==NULL){
                std::cout<<"list is empty"<<std::endl; 
            }else{
                
            while(temp->key==k){
                prev = head;
                head = head->next;     
                temp = head;
                delete prev;
                
            }
                
            prev = head;
            temp = head->next;

            while(temp->next!=NULL){

                if(temp->key == k){
                    del = temp;
                    temp=temp->next;
                    prev->next = temp;
                    delete del;
                }else{
                    temp = temp->next;
                    prev = prev->next;
                    }
                }

                if(temp->key == k){
                    prev->next = NULL;     
                    delete temp;
                }

            }

        }
    
        template<typename Key, typename Info>
        void Sequence<Key, Info>::ereaseByInfo(const Info &i){  

            Node* temp = head;
            Node* prev = NULL;
            Node* del = new Node;
            if(temp==NULL){
                std::cout<<"list is empty"<<std::endl; 
            }else{
                
            while(temp->info==i){
                prev = head;
                head = head->next;     
                temp = head;
                delete prev;
                
            }
                
            prev = head;
            temp = head->next;

            while(temp->next!=NULL){

                if(temp->info == i){
                    del = temp;
                    temp=temp->next;
                    prev->next = temp;
                    delete del;
                }else{
                    temp = temp->next;
                    prev = prev->next;
                    }
                }

                if(temp->info == i){
                    prev->next = NULL;     
                    delete temp;
                }

            }

        }
    

        template<typename Key, typename Info>
        int Sequence<Key, Info>::size(){ 

            if(head==NULL) return 0;
            int i = 0;
            Node* node = head;
            while(node!=NULL){
                i++;
                node=node->next;
                }
            return i;
       
        }
        
        template<typename Key, typename Info>
        void Sequence<Key, Info>::print(){
            
            if(head==NULL){
                std::cout << "list is empty" << std::endl;
            }else{
            Node* temp = head;
            std::cout << "-----------------------" << std::endl;
            while(temp!=NULL){
                std::cout << "Key: "<<temp->key<<" | Info: "<<temp->info<<std::endl;
                temp = temp->next;
            }
            std::cout << "-----------------------" << std::endl;
            }
        }

        template<typename Key, typename Info>
        typename Sequence<Key, Info>::Node* Sequence<Key, Info>::getFromPosition(int position){ 

            if(position == 0){
                return head;
            } 
            if(position < 0 || position > size()){
                std::cout << "no such position" << std::endl;
                return NULL;
            }

            int i = 0;
            Node* temp = head;

            while(i<position){
                temp = temp->next;
                i++;
            }
            return temp;

        }
        
        template<typename Key, typename Info>
        Sequence<Key, Info>::Sequence(const Sequence &s){ 
            this->head = NULL;
            Node* temp = s.head;
            while(temp!=NULL){
                this->pushBack(temp->key, temp->info);
                temp = temp->next;
            }
       
        }

        template<typename Key, typename Info>
        Sequence<Key, Info>& Sequence<Key, Info>::operator=(Sequence<Key, Info> &s){ 

            if(this == &s){
                std::cout << "same lists" << std::endl;
            }else{

            Node* del = head;
            Node* temp = new Node;
            while(del!=NULL){
                temp = del->next;
                delete del;
                del = temp;
            }
            
            this->head = NULL;
            temp = s.head;
            while(temp!=NULL){
                this->pushBack(temp->key, temp->info);
                temp = temp->next;
            }
            }
            return *this;
        }

        template<typename Key, typename Info>
        Sequence<Key, Info>& Sequence<Key, Info>::operator+(Sequence &s){  
            
            if(this==&s){
                std::cout << "same lists" << std::endl;
            }else{

            Node* temp = s.head;
            while(temp!=NULL){
                pushBack(temp->key, temp->info);
                temp = temp->next;
                }
            }
            return *this;
        }

        template<typename Key, typename Info>
        void Sequence<Key, Info>::removeAll(){ 
            
            Node* temp = head;
            Node* del = new Node;
            while(temp!=NULL){
                del = temp;
                temp = temp->next;
                delete del;
            }
            head = NULL;

        }

        template<typename Key, typename Info>
        bool Sequence<Key, Info>::isEmpty(){ 
            if(head==NULL)
                return true;    
            else
                return false;
        }

        template<typename Key, typename Info>
        typename Sequence<Key, Info>::Node* Sequence<Key, Info>::getKey(const Key &k){

            Node* curr = head;
            while(curr!=NULL){
                if(curr->key == k)
                    return curr;
                curr = curr->next;
            }

        }  

        template<typename Key, typename Info>
        typename Sequence<Key, Info>::Node* Sequence<Key, Info>::getInfo(const Info &i){
                
            Node* curr = head;
            while(curr!=NULL){
                if(curr->info == i)
                    return curr;
                curr = curr->next;
            }
        };

#endif