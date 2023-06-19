#include <bits/stdc++.h>
using namespace std;

class CustomStack
{
private:
    int *arr;
    int top;
    int size;

public:
    CustomStack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }
    // bool isOverFlow()
    // {
    //     if (top >= size)
    //     {
    //         throw invalid_argument(" STACK OVERFLOW");
    //     }
    // }
    void push(int val)
    {
        if (top < size - 1)
        {
            arr[++top] = val;
        }
        else
        {
            // this->grow();
            throw invalid_argument(" STACK OVERFLOW");
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            throw invalid_argument(" STACK UNDERFLOW");
        }
    }
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            throw invalid_argument(" STACK UNDERFLOW");
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    // to grow the size if we wwant

    void grow()
    {
        int *temp = new int[size * 2];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
            cout << temp[i] << arr[i] << endl;
        }
        delete (arr);
        arr = temp;
        size = size * 2;
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class CustomStackLL
{
    ListNode *top;
    ListNode *head;

public:
    CustomStackLL()
    {

        head = new ListNode();
        top = NULL;
    }
    void push(int val)
    {
        if (top == NULL)
        {
            ListNode *temp = new ListNode(val);
            head = top = temp;
        }
        else
        {

            ListNode *temp = new ListNode(val);
            top->next = temp;
            top = top->next;
        }
    }
    void pop()
    {

        if (this->top != NULL)
        {
            if (head->next == NULL)
            {

                top = NULL;
                head = NULL;
                return;
            }
            ListNode *temp = head;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            top = temp;
            return;
        }
        else
        {
            throw invalid_argument(" STACK UNDERFLOW");
        }
    }
    int peek()
    {
        if (top != NULL)
        {
            return top->val;
        }
        else
        {
            throw invalid_argument(" STACK UNDERFLOW");
        }
    }
    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        return false;
    }
    // to grow the size if we wwant
};

class CustomStackLL2
{
    ListNode *top;

public:
    CustomStackLL2()
    {
        top = NULL;
    }
    void push(int val)
    {
        ListNode *temp = new ListNode(val);
        temp->next = top;
        top = temp;
    }
    void pop()
    {
        if (top == NULL)
            throw invalid_argument(" STACK UNDERFLOW");
        ListNode *temp = top;
        top = top->next;
        delete (temp);
    }
    int peek()
    {
        if (top != NULL)
        {
            return top->val;
        }
        else
        {
            throw invalid_argument(" STACK UNDERFLOW");
        }
    }
    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        return false;
    }
    // to grow the size if we wwant
};
int main()
{

    CustomStackLL c;
    c.push(10);
    c.push(1);
    c.push(12);
    c.push(24);
    c.push(45);
    // c.grow();
    c.push(40);
    cout << c.peek() << endl;
    c.pop();
    cout << c.peek() << endl;
    c.pop();
    c.pop();
    cout << c.peek() << endl;

    cout << c.peek();
    c.isEmpty() ? cout << "no" : cout << "yes";

    c.push(10);
    c.push(10);
    return 0;
}