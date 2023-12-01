class Node:
    def __init__(self,val):
        self.val = val
        self.next = None
        
class LinkedList:
    def __init__(self):
        self.head = None
        
    def insert(self,data):
        Newnode = Node(data)
        Newnode.next = self.head
        self.head = Newnode
        
    def print_list(self):
        current=self.head
        while current:
            print(current.val)
            current=current.next

LL=LinkedList()
LL.insert(3)
LL.insert(4)
LL.insert(5)
LL.print_list()
