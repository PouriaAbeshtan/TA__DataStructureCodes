#include <iostream>
using namespace std;
template < typename input_type > 
class Node { 
public: 
    input_type data; 
    Node* next; 
    Node* previous; 
    Node(input_type value = input_type()){ 
        this->data = value; 
        this->next = nullptr; 
        this->previous = nullptr;
    } 
};  

template < typename input_type > 
class link_list_queue{
    private:
        Node<input_type>* top;
        Node<input_type>* bottom;
        Node<input_type>* end;
    public:
        link_list_queue(){
            top = nullptr;
            bottom = nullptr;
            end = nullptr;
        }
        //=========================================================================================================================
        void insert(input_type value){
            Node<input_type>* newNode = new Node<input_type>(value);
            if(top == nullptr){
                top = newNode;
                bottom = newNode;
                end = new Node<input_type>(input_type());
                top->next = end;
                end->previous = top;
            }else{
                newNode->previous = top;
                top->next = newNode;
                top = newNode;
                top->next = end;
                end->previous = top;
            }
        } 
        //=========================================================================================================================
        input_type dequeue(){
            if(bottom->next != nullptr){  
                input_type value = bottom->data;
                bottom = bottom->next;
                bottom->previous = nullptr;
                return value;      
            }else{
                return input_type();
            }
        }
};
int main(){
    link_list_queue<int> a;
    a.insert(5);
    a.insert(50);
    a.insert(22);
    a.insert(8);
    cout<<a.dequeue()<<'\n';
    cout<<a.dequeue()<<'\n';
    cout<<a.dequeue()<<'\n';
    cout<<a.dequeue()<<'\n';
    cout<<a.dequeue()<<'\n';
    cout<<a.dequeue()<<'\n';
    cout<<a.dequeue()<<'\n';
    return 0;
}