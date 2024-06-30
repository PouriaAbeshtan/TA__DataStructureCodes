#include <iostream>
using namespace std;
template < typename input_type > 
class Node { 
public: 
    input_type data = 0; 
    Node* next = nullptr; 
    Node* previous = nullptr; 
    Node(input_type value){ 
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
        Node<input_type>* temp ;
        int max = 0, count = 0;
    public:
        link_list_queue(int m){
            max = m;
            top = nullptr;
            bottom = nullptr;
            for(int i = 0 ; i < max ; i++){
                this->make_queue(false);
            }
            temp = bottom; // will be use in fill_data function to give value to link list nodes
        }
        //=========================================================================================================================
        bool is_empty(){
            return (count == 0);
        }
        //=========================================================================================================================
        bool is_full(){
            return (((count+1) % max == 0) && top == bottom->previous);
        }
        //=========================================================================================================================
        void make_queue(input_type value){
            Node<input_type>* newNode = new Node<input_type>(value);
            if(is_empty() && top == nullptr){
                top = newNode;
                bottom = newNode;
            }else{
                newNode->previous = top;
                top->next = newNode;
                top = newNode;
                top->next = bottom;
                bottom->previous = top;
            }
        } 
        //=========================================================================================================================
        void insert(input_type value){
            if(!is_full()){
                temp->data = value;
                temp = temp->next;
                count++;
            }else{
                cout<<value<<" can`t be puy in queue.\n";
            }
        }
        //=========================================================================================================================
        input_type dequeue(){
            if(!is_empty()){
                input_type value = bottom->data;
                bottom = bottom->next;
                top = top->next;
                count--;
                return value;
            }else{
                return false;
               
            }
        }
};
int main(){
    link_list_queue<int> a(5);
    a.insert(75);
    a.insert(58);
    a.insert(13);
    a.insert(49);
    cout<<a.dequeue()<<'\n';
    a.insert(64);
    cout<<a.dequeue()<<'\n';
    cout<<a.dequeue()<<'\n';
    a.insert(60);
    a.insert(95);
    a.insert(-53);
    a.insert(12);
    cout<<a.dequeue()<<'\n';
    cout<<a.dequeue()<<'\n';
    cout<<a.dequeue()<<'\n';
    cout<<a.dequeue()<<'\n';
    cout<<a.dequeue()<<'\n';
    cout<<a.dequeue()<<'\n';
    cout<<a.dequeue()<<'\n';
    cout<<a.dequeue()<<'\n';
    return 0;
}