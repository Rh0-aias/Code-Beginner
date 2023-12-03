#include <iostream>

class Node{
    public:
        //Constructors
        Node() : val(0), next(nullptr) {}
        Node(double init_val, Node* init_next = nullptr): val(init_val), next(init_next) {}
        //Deconstructor
        ~Node(){}
        //Methods
        double getValue(){return val;}
        void setValue(double val){this->val = val;}
        Node* getNext(){return next;}
        void setNext(Node* Nextnode){next = Nextnode;}
    private:
        double val;
        Node* next;
};

class SinglyLinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        //Constructor
        SinglyLinkedList(Node* init_head=nullptr, Node* init_tail=nullptr, int init_length=0): head(init_head), tail(init_tail), length(init_length) {}
        //Deconstructor (Free the memory)
        ~SinglyLinkedList(){while (head != nullptr) {remove_head();}}
        
        void head_insert(double data){
            Node* new_node = new Node(data);
            new_node->setNext(head);
            head = new_node;
            length += 1;
            if(tail == nullptr){tail=new_node;}
        }
    
        void tail_insert(double data){
            Node* new_node = new Node(data);
            if(tail == nullptr){
                head = tail = new_node;
            }
            else{
                tail->setNext(new_node);
                tail = new_node;
            }
            length += 1;
        }
    
        // Insert before N-th node
        void insert(int N, double data){
            if (N < 1){
                std::cout<<"Error! Position of insertion N="<<N<<" has to be a postive integer!\n";
            }
            else if (N > length + 1){
                std::cout<<"Error! Position of insertion N="<<N<<" exceeds the length (L="<<length<<") of current SinglyLinkedList!\n";
            }
            else if (N == 1){
                head_insert(data);
            }
            else if (N == length + 1){
                tail_insert(data);
            }
            else{
                Node* previous = head;
                Node* current = previous->getNext();
                Node* new_node = new Node(data);
                while(N>2){
                    previous = current;
                    current = current->getNext();
                    N -= 1;
                }
                previous->setNext(new_node);
                new_node->setNext(current);
                length += 1;
            }
        }
    
        void remove_head(){
            if(head){
                Node* oldHead = head;
                head = head->getNext();
                // Free the memory
                delete  oldHead;
                length -= 1;
            }
            //After excute above step, if SLL becomes None, tail also needs to be set to None
            if (head == nullptr){tail = nullptr;}
        }
    
        //remove N-th node
        void remove(int N){
            if(head == nullptr){return;}
            if(N > length){std::cout<<"Error! Try to delete " << N <<"-th node, but it does not exist!\n";return;}
            if(N == 1){remove_head();}
            else {
                Node* previous = head;
                Node* current = previous->getNext();              
                while(N > 2){
                    previous = current;
                    current = current->getNext();
                    N -= 1;
                }
                previous->setNext(current->getNext());
                // If the tail node is deleted, we need to update the tail
                if(current->getNext() == nullptr){tail=previous;}
                length -= 1;
                // Free the memory
                delete current;
            }
            
        }
     
        void print_list(){
            std::cout<<"Length:"<<length<<std::endl;
            Node* current = head;
            while(current){
                std::cout<<current->getValue()<<"→";
                current=current->getNext();
            }
            std::cout<<"\n";
        }
    
};

int main(){
    SinglyLinkedList sll;
    sll.head_insert(2);
    sll.head_insert(3);
    sll.head_insert(4);
    sll.head_insert(5);
    sll.print_list();
    sll.tail_insert(1);
    sll.print_list();
    sll.insert(3,777);
    sll.print_list();
    sll.insert(10,777);
    sll.insert(-1,777);
    sll.remove_head();
    sll.print_list();
    sll.remove(2);
    sll.print_list();
    sll.remove(4);
    sll.print_list();
    sll.remove(4);
    sll.remove(1);
    sll.remove(2);
    sll.print_list();
    sll.remove(1);
    sll.print_list();
    return 0;
}
