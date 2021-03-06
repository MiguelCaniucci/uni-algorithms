#ifndef AVL_H_
#define AVL_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cstdlib>

enum order{
    ascending = 1,
    descending = 0
};

template <typename Key, typename Info>
class Dictionary{

private:

    struct Node{

        Key key;
        Info info;
        Node* left;
        Node* right;
        int height;
        
    };

    Node* root;

    bool insert(Node*& node, const Key &k, const Info &i){  
    
    if (node == NULL){  
            Node* new_node = new Node;
            new_node->key = k;          
            new_node->info = i;
            new_node->left = NULL;
            new_node->right = NULL;
            new_node->height = 1;
            node = new_node;
            return true;    
    }

    if (k < node->key)  
        insert(node->left, k, i);  
    else if (k > node->key)  
        insert(node->right, k, i);  
    else 
        return false;  

    node->height = height(node);

    int balance = getBalance(node);

    if (balance > 1 && k < node->left->key)  
        rotateToRight(node);  
  
    if (balance < -1 && k > node->right->key)  
        rotateToLeft(node);  
  
    if (balance > 1 && k > node->left->key)  
    {  
        node->left = rotateToLeft(node->left);  
        rotateToRight(node);  
    }  
  
    if (balance < -1 && k < node->right->key)  
    {  
        node->right = rotateToRight(node->right);  
        rotateToLeft(node);  
    }  
    
    return true;  
    }


    Node* erease(Node* &node, const Key &k){

        if(node==NULL)
            return node;

        if ( k < node->key ){  
            node->left = erease(node->left, k);  
  
        }else if( k > node->key ){
            node->right = erease(node->right, k);  

        }else{
            Node *temp = NULL;

            if(node->left == NULL || node->right == NULL){
            
                if(node->left != NULL)   
                    temp = node->left;  
                else
                    temp = node->right;  

                if(temp == NULL){
                    temp = node;
                    node = NULL;                    
                }else{ 
                    node->key = temp->key;
                    node->info = temp->info;
                    node->left = temp->left;
                    node->right = temp->right;
                    node->height = temp->height;
                    delete temp;
                }

            }else{

                Node* temp = minValueNode(node->right);

                node->key = temp->key;
                node->info = temp->info;  

                node->right = erease(node->right, temp->key);
                
            }
            
            if (node == NULL)  
                return node;  
           
            } 
            
            node->height = 1 + max(height(node->left),  
                                height(node->right));  
            
            int balance = getBalance(node);  

            if (balance > 1 && getBalance(node->left) >= 0){  
               return rotateToRight(node);  
            }        
            if (balance > 1 && getBalance(node->left) < 0)  
            {  
                node->left = rotateToLeft(node->left);  
                return rotateToRight(node);  
            }  
        
            if (balance < -1 && getBalance(node->right) <= 0){
                return rotateToLeft(node);  
            }     
            if (balance < -1 && getBalance(node->right) > 0)  
            {  
                node->right = rotateToRight(node->right);  
                return rotateToLeft(node);  
            }  

        return node;  
    }


    void printAscending(Node *node) const{  
        if(node!=NULL){ 
        printAscending(node->left);
        std::cout << node->key << " ";
        printAscending(node->right);
        }
    }


   void printDescending(Node *node) const{ 
       if(node!=NULL){ 
        printDescending(node->right);
        std::cout << node->key << " ";
        printDescending(node->left);
       }
   }


   void ereaseAll(Node* &node){
       
       if(node!=NULL){
           ereaseAll(node->left);  
           ereaseAll(node->right);  
           delete node;             
           node = NULL;             
       }
   
    }


    void copyTree(Node* &copiedTreeRoot, Node* otherTreeRoot){
    
        if (otherTreeRoot == NULL){    

            copiedTreeRoot = NULL;  

        }else{
            
            copiedTreeRoot = new Node;                       
            copiedTreeRoot->key = otherTreeRoot->key;       
            copiedTreeRoot->info = otherTreeRoot->info;

            copyTree(copiedTreeRoot->left, otherTreeRoot->left);       
            copyTree(copiedTreeRoot->right, otherTreeRoot->right);     
        
            }   
    }


    int height(Node *node) const{

        if(node==NULL)
            return 0;
        else
            return max(height(node->left), height(node->right)) + 1;
    }


    int max(int a, int b) const{

        if(a>b)
            return a;
        else
            return b; 
    }


    int min(int a, int b) const{
        
        if(a<b)
            return a;
        else
            return b; 
    }


    Node* rotateToRight(Node* &node){

        Node* L = node->left;   
        Node* LR = L->right;

        L->right = node;
        node->left = LR;

        node->height = max(height(node->left), height(node->right)) + 1; 
        L->height = max(height(L->left), height(L->right)) + 1;
        
        node = L;

        return node;
    }


    Node* rotateToLeft(Node* &node){

        Node* R = node->right;
        Node* RL = R->left;
        
        R->left = node;
        node->right = RL;
        
        node->height = max(height(node->left), height(node->right)) + 1; 
        R->height = max(height(R->left), height(R->right)) + 1;
        
        node = R;

        return node;
    }


    int getBalance(Node* node) const{

        if(node==NULL)
            return 0;
        return height(node->left) - height(node->right);
    }


    void recDisplay(Node * root, int space) const{

        if (root == nullptr) {
            return;
        }

        space += 10;

        this->recDisplay(root->right, space);

        std::cout << std::endl << std::endl;

        for (int i = 10; i < space; i++) {
            std::cout << " ";
        }
        std::cout << root->key << std::endl;;

        this->recDisplay(root->left, space);

    }


    void recDisplayGood(Node * root, int space) const{

        if (root == nullptr) {
            return;
        }

        space = height(maxValueNode(root));

        for (int i = 0; i < space; i++) {
            std::cout << " ";
        }
        
        std::cout << root->key << std::endl;
        
        for (int i = 0; i < space; i++) {
            std::cout << " ";
        }

        std::cout << std::endl;

    }

    int numberOfElements(Node* node) const{
    
       
        if(node==NULL)
            return 0;
        return 1 + numberOfElements(node->left) + numberOfElements(node->right);
    }


    Node* minValueNode(Node* node) const{  
        
        if(node!=NULL)
            return node;

        Node* current = node;  
    
        while (current->left != NULL)  
            current = current->left;  
    
        return current;  
        }  


    Node* maxValueNode(Node* node) const{  
    
        if(node!=NULL)
            return node;

        Node* current = node;  
    
        while (current->right != NULL)  
            current = current->right;  
    
        return current;  
        }  


    void displayNode(Node* node) const{

        if(node == NULL)
            return;
        std::cout << "********NODE INFO********" << std::endl;            
        std::cout << "Key: " << node-> key << std::endl;
        std::cout << "Info: " << node-> info << std::endl;
        std::cout << "Height: " << node-> height << std::endl;
        std::cout << "Balance: " << getBalance(node) << std::endl;
        std::cout << "*************************" << std::endl;
    }

    bool search(Node* &node, const Key &k){

        if(node==NULL)
            return false;
        
        if(k < node->key)
            return search(node->left, k);
        else if(k > node->key)
            return search(node->right, k);
        else
            return true;
        
    }

    Node* getNode(Node* node, const Key &k) const{

        if(node==NULL)
            return node;

        if(k < node->key)
            return getNode(node->left, k);
        if(k > node->key)
            return getNode(node->right, k);
        else
            return node;

    }

    /********************************/
    /*  NOT A PART OF THE PROJECT
        JUST LEARNING FOR EXAM    */

    double sumOfKeys(Node* node){
        if(!node)
            return 0;
        else
            return node->key + sumOfKeys(node->left) + sumOfKeys(node->right);
    }

    /********************************/



public:

    Dictionary();
    Dictionary(const Dictionary<Key, Info> &rhs);
    ~Dictionary();
    void insert(const Key &k, const Info &i);
    void erease(const Key &k);
    void ereaseAll();
    void print(int ord) const;
    bool isEmpty()const {return (root==NULL);};
    const Dictionary<Key, Info>& operator=(const Dictionary<Key, Info> &rhs);
    int treeHight() const;
    void display() const;
    int size() const;
    void printInfo() const; 
    bool search(const Key &k);
    Info& getInfo(const Key &k) const;

    double averageKey();

    void fillWithRandom(){  

        Key k;
        Info i;

        for(int n = 0; n < 8; n++){
            k = rand() % 50;
            i = rand() % 50;
            insert(k, i);
        }
    }


    void publicPrintPrettyTree();
    
    void printPrettyTree(Node* node, int space){

        for(int i = 0; i < space; i++){
            std::cout << std::endl;
        }

        space += 10;

        if(!node)
            return;
    
        for(int i = 0; i < (size()*10)-space; i++)
            std::cout << " ";
        
        std::cout << node->key << std::endl;

        printPrettyTree(node->left, space);
        printPrettyTree(node->right, space);

    }

};

//PUBLIC METHODS IMPLEMENTATION

template<typename Key, typename Info>
Dictionary<Key, Info>::Dictionary(){
   
    root = NULL;

}


template<typename Key, typename Info>
Dictionary<Key, Info>::~Dictionary(){

}


template<typename Key, typename Info>
void Dictionary<Key, Info>::insert(const Key &k, const Info &i){

   insert(root, k, i);

}


template<typename Key, typename Info>
void Dictionary<Key, Info>::print(int ord) const{
   
    if(root==NULL){
        std::cout << "Tree is empty" << std::endl;
    }else{
        if(ord == ascending){
            printAscending(root);
            std::cout<<std::endl;
        }else if(ord == descending){
            printDescending(root);
            std::cout<<std::endl;
        }else{
            std::cout << "There is no such order" << std::endl;
        }
    }
}


template<typename Key, typename Info>
void Dictionary<Key, Info>::ereaseAll(){

    ereaseAll(root);

}


template<typename Key, typename Info>
Dictionary<Key, Info>::Dictionary(const Dictionary<Key, Info> &rhs){

    if (rhs.root == NULL){ //rhs is empty
        this->ereaseAll(); 
        this->root = NULL;
    }else{
        copyTree(this->root, rhs.root);
    }
}


template<typename Key, typename Info>
const Dictionary<Key, Info>& Dictionary<Key, Info>::operator=(const Dictionary<Key, Info> &rhs){

    if(this->root != rhs.root){ 

        if(root != NULL)
            this->ereaseAll();  
        
        if(rhs.root==NULL){     
            this->ereaseAll();  
            root = NULL;
        }else{
            copyTree(this->root, rhs.root); 
        }
    }
    return *this;
}


template<typename Key, typename Info>
int Dictionary<Key, Info>::treeHight() const{
  
    return height(root);

}


template<typename Key, typename Info>
void Dictionary<Key, Info>::display() const{

	if (this->isEmpty()) {
		std::cout << "Tree is empty" << std::endl;
	}else {
		std::cout << "\n***************************************\n";
		this->recDisplay(this->root, 0);
		std::cout << "\n***************************************\n\n";
	}
}


template<typename Key, typename Info>
int Dictionary<Key, Info>::size() const{
    
    return numberOfElements(root);

}


template<typename Key, typename Info>
void Dictionary<Key, Info>::erease(const Key &k){

    erease(root, k);

}

template<typename Key, typename Info>
void Dictionary<Key, Info>::printInfo() const{

    std::cout << "*****TREE INFO*****" << std::endl;
    std::cout << "Elements: ";
    print(ascending);
    std::cout << "Size: " << size() << std::endl;
    std::cout << "Height: " << height(root) << std::endl;
    std::cout << "*******************" << std::endl;

}

template<typename Key, typename Info>
bool Dictionary<Key, Info>::search(const Key &k) {

    return search(root, k);

}

template<typename Key, typename Info>
Info& Dictionary<Key, Info>::getInfo(const Key &k) const{

    Node* i = getNode(root, k);
    if(i!=NULL)
        return i->info;

    throw std::exception();
    
}

template<typename Key, typename Info>
double Dictionary<Key, Info>::averageKey(){

        return sumOfKeys(root)/numberOfElements(root);

}

template<typename Key, typename Info>
void Dictionary<Key, Info>::publicPrintPrettyTree(){

    printPrettyTree(root, 0);

}

#endif