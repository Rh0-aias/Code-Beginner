class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
        
class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0
        
    def head_insert(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node
        if self.tail is None:
            self.tail = new_node
        self.length += 1
        
    def tail_insert(self, data):
        new_node = Node(data)
        if self.tail is None:
            self.head = self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
        self.length += 1
        
    def insert(self, N, data):
        if N <1 or not isinstance(N,int):
            raise ValueError("Error! Position of insertion N="+str(N)+" has to be a postive integer!\n")
        if N > self.length+1:
            raise ValueError("Error! Position of insertion N="+str(N)+" exceeds the length (L="+str(self.length)+") of current SinglyLinkedList!\n")
        if N == 1:
            self.head_insert(data)
            return
        if N == self.length+1:
            self.tail_insert(data)
            return
        previous = self.head
        current = previous.next
        new_node = Node(data)
        while N > 2:
            previous, current = current, current.next
            N -= 1
        previous.next = new_node
        new_node.next = current
        self.length += 1        
        
    def remove_head(self):
        if self.head is not None:
            # self.head is automatically reclaimed by the garbage collector if no longer referenced
            self.head=self.head.next
            self.length -= 1
        # After excute above step, if SLL becomes None, self.tail also needs to be set to None
        if self.head is None:
            self.tail = None
        
    def remove(self, N):#remove N-th node
        if self.head is None:
            return
        if N > self.length:
            raise ValueError("Error! Try to delete " + str(N) + "-th node, but it does not exist!\n")
        if N ==1:
            self.remove_head()
        else:
            previous = self.head
            current = previous.next
            while N > 2:
                previous, current = current, current.next
                N -= 1
            previous.next = current.next
            # If the tail node is deleted, we need to update the tail
            if current.next is None:
                self.tail = previous
            self.length -= 1
          
    def print_list(self):
        print("Length:",self.length)
        current=self.head
        while current:
            print(current.data, end="→")
            current=current.next
        print("\n")
        
        
#Test            
sll = SinglyLinkedList()

sll.head_insert(3)
sll.head_insert(2)
sll.head_insert(1)
print("After head inserts:")
sll.print_list()

sll.tail_insert(4)
sll.tail_insert(5)
print("After tail inserts:")
sll.print_list()

sll.insert(3, 2.5)
print("After inserting 2.5 at position 3:")
sll.print_list()

sll.remove_head()
print("After removing head:")
sll.print_list()

sll.remove(3)
print("After removing the element at position 3:")
sll.print_list()

try:
    sll.insert(-1, 0)
except ValueError as e:
    print(e)

try:
    sll.remove(10)
except ValueError as e:
    print(e)
    
try:
    sll.insert(3.5, 0)
except ValueError as e:
    print(e)
