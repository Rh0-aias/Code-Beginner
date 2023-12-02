class Node{
    public:
        double val;
        Node* next;
    //Constructors
    Node() : val(0), next(nullptr) {}
    Node(double init_val, Node* init_next = nullptr): val(init_val), next(init_next) {}
    //Deconstructor
    ~Node(){}
}

int main() {


}
