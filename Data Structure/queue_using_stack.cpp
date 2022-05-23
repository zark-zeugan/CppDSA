#include <iostream>
#include <stack>


class MyQueue {
public:
    MyQueue(){

    }
    
    void push(int x) {
        if(empty())
        {
            s1.push(x);
        }
        else
        {
            while(!empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {

        return s1.top();
        
    }
    
    bool empty() {

        return s1.empty();        
    }
private: 
    std::stack<int> s1;
    std::stack<int> s2;

};



int main()
{
    int data[] = {1,2,3,4,5};
    MyQueue queue;

    for(int val:data)
    {
        queue.push(val);
    }

    std::cout << "The first element is - " << queue.peek() << std::endl;
    queue.pop();
    std::cout << "The first element is - " << queue.peek() << std::endl;


    
    return 0;
}