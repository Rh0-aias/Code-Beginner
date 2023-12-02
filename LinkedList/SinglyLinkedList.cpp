class Node{
    public:
        //Constructors
        Node() : val(0), next(nullptr) {}
        Node(double init_val, Node* init_next = nullptr): val(init_val), next(init_next) {}
        //Deconstructor
        ~Node(){}
        //Methods
        double getValue(){ return val; }
        void setValue(double val){ this->val = val; }
        Node* getNext(){ retun next; }
        void setNext(Node* Nextnode){ next = Nextnode; }
    private:
        double val;
        Node* next;
}




int main(){


}
