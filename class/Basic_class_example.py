class MyClass:
    StaticVar = 0        # Sattic variables are shared with all the instances of thsi class. It can be modified! 
    StaticConstVar = 0   # Constant static variables but It cann also be modified in Python.
                         # But we can use attribute decorator in python
    __StaticConstVariable = 123 # Constant static variables. Convention: private variables with __ in the front 
    @property
    def StaticConstVariable(self):
        return MyClass.__StaticConstVariable

    def __init__(self, init_a=0, init_b=0.0, init_c=0):
        self.__a = init_a  # Convention: private variables with __ in the front
        self.__b = init_b  # Convention: private variables with __ in the front
        self.c = init_c
        self.d = 0
        print("MyClass is being created")

    def __del__(self):
        print("MyClass is being deleted")

    def func_inside(self):
        print("Function can be defined inside class")

    def func_outside(self):
        return external_func()

    def set_value(self, a):
        self.__a = a

    def get_value(self):
        return self.__a

# External function can be called in class
def external_func():
    return "Function can be defined outside class"

# Testing
if __name__ == "__main__":
    print("Demonstration of very basic Python class usage.(without inheritance)")
    obj = MyClass(10, 10.5, 11)
    obj1 = MyClass(10, 12.5, 13)
    obj.c = 12
    obj.d = 16
    MyClass.StaticVar = 666
    obj.set_value(777)
    print(f"obj's private __a is set to: {obj.get_value()}")
    print(f"Use 'ClassName.' for class variable: MyClass.StaticVar={MyClass.StaticVar}")
    print(f"Use '.' for instance variable: obj.StaticVar={obj.StaticVar}")
    print(f"Different instances have the same StaticVar: obj.StaticVar=obj1.StaticVar={obj1.StaticVar}")
    print(f"c={obj.c}")
    print(f"d={obj.d}")
    obj.func_inside()
    external_func()
    print(f"Testing of attribute decorator : MyClass.StaticConstVar={MyClass.StaticConstVar}")
