#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

template<class T>
struct Node
{
    T m_data;
    Node *m_right;
    Node *m_left;

    Node(T data):m_data(data), m_right(nullptr), m_left(nullptr){}

    friend std::ostream &operator<<(std::ostream &os, Node<T> const &n) { 
        return os << n.m_data;
    }
};

template<class T>
struct BST
{
    Node<T> *m_root;
    BST():m_root(nullptr){}

    Node<T>* insert(Node<T>* current, T data){
        if(current==nullptr) return new Node<T>(data);
        else{
            if(data < current->m_data){
                current->m_left = insert(current->m_left, data);
            }else if(data > current->m_data){
                current->m_right = insert(current->m_right, data);
            }
        }
        return current;
    }

    void insert(T data){
        m_root = insert(m_root, data);
    }

    Node<T>* find(T key){
        Node<T> *temp = this->m_root;

        while (temp != NULL) {
            if (key > temp->m_data) {
                temp = temp->m_right;
            }
            else if (key < temp->m_data) {
                temp = temp->m_left;
            }
            else
                return temp; 
        }
        cout << "No se encontro el nodo" << endl;
        return 0;
    }


    void LevelTraverse(){
        Node<T> *temp = this->m_root;
        int a=1;
        int b=1;
        if (temp == NULL)
        return;
        while(temp->m_left->m_left != NULL)
        {
            temp= temp->m_left;
            a++;
        }
        if (temp->m_left != NULL || temp->m_right != NULL)
        {
            cout << temp->m_left->m_data << " - ";
            cout << temp->m_right->m_data << " - ";
        }
        temp = this->m_root;
        while(temp->m_right->m_right != NULL)
        {
            temp= temp->m_right;
            b++;
        }
        if (temp->m_left != NULL || temp->m_right != NULL)
        {
            cout << temp->m_left->m_data << " - ";
            cout << temp->m_right->m_data << " - ";
        }
    }

    Node<T>* minNode(Node<T>* current){
        if(current == NULL)
            return NULL;
        else if(current->m_left == NULL)
            return current;
        else
            return minNode(current->m_left);
    }

    Node<T>* deleteNode(Node<T>* current, T key){
        if(current==nullptr) return current;

        if(key < current->m_data){
            current->m_left = deleteNode(current->m_left, key);
        }else if(key > current->m_data){
            current->m_right = deleteNode(current->m_right, key);
        } else {
            if (current->m_left == nullptr) {
                Node<T>* temp = current->m_right;
                free(current);

                return temp;
            } else if(current->m_left == nullptr) {
                Node<T>* temp = current->m_left;
                free(current);

                return temp;
            }

            Node<T>* temp = minNode(current->m_right);

            current->m_data = temp->m_data;
            current->m_right = deleteNode(current->m_right, temp->m_data);
        }

        return current;
    }

    void deleteNode(T key){
        deleteNode(m_root, key);
    }

    int sizeTree(){
       Node<T> *temp = this->m_root;
       int right_height=-1;
       int left_height=-1;
       
       if(temp!=NULL)
       {
           if(temp->m_right!=NULL)
           {
               right_height=sizeTree(temp->m_right);
           }
           if(temp->m_left!=NULL)
           {
               left_height=sizeTree(temp->m_left);
           }
           
           if(right_height>left_height)
           {
               return(right_height+1);
           }
           else
           {
               return(left_height+1);
           }
       } 
       else
       {
        return NULL;
       }
    }

    void removeLeaf(){
       Node<T> *temp = this->m_root;
       Node<T> *previous;
   
       if(temp!=NULL)
       { 
        previous=temp;
        
        if(temp->m_right)
        {
           temp=temp->m_right;
           
           if(temp->m_right || temp->m_left)
                removeLeaf(temp);
           else
           {  
             previous->m_right=NULL;
             delete temp;
           }
         }
         
         if(previous->m_left)
         {
           temp=previous->m_left;
           
           if(temp->m_right || temp->m_left)
               removeLeaf(temp);  
           else
           {
               previous->m_left=NULL;
               delete temp;
           }
         }
       }
    }

    
    bool isAVL(){
    if (!m_root)
    {
        return true;
    }
    Node<T> *left_t = this->m_root->m_left;
    Node<T> *right_t = this->m_root->m_right;

    /*int left = left_t.sizeTree();
    int right = right.sizeTree();
 
    int diff = (left > right) ? left - right: right - left;
 
    if (diff <= 1 && isAVL (m_root->m_left) && isAVL (m_root->m_right))
        return true;
    return false;
    */
    }
};



int main() {

    BST<int> t1 = BTS<int>();

    t1.insert(8);
    t1.insert(1);
    t1.insert(5);
    t1.insert(3);
    t1.insert(7);
    t1.removeLeaf;
    

    return 0;
};