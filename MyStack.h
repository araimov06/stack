#ifndef MyStack_h
#define MyStack_h

template <typename stack>
class MyStack{
    private:
        class MyListNode{
            private:
                stack value;
                MyListNode* next;

            public:
                MyListNode(stack value){this -> value = value; this -> next = nullptr;};
                stack getValue() const {return value;};
                void setNext(MyListNode* nextNode) {next = nextNode;};
                MyListNode* getNext() const {return next;};
        };
        MyListNode* head;
    
    public:
        MyStack(){head = nullptr;}
        ~MyStack(){
            while(!empty()){
                pop();
            }
        }
        
        bool empty() const {
            return head == nullptr;
        }

        stack top() const{
            if (empty()) {
                throw std::logic_error("Stack is empty\n");
            }
            return head->getValue();
        }

        void pop() {
            if (empty()) {
                throw std::logic_error("Stack is empty\n");
            }
            MyListNode* temp = head;
            head = head->getNext();
            delete temp;
        }

        void push(stack value) {
            MyListNode* newNode = new MyListNode(value);
            newNode->setNext(head);
            head = newNode;
        }
};

#endif
