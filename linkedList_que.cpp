#include <bits/stdc++.h>

using namespace std;

class Node
{
    int value;
    Node *next;

public:
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
    Node(int value, Node *next)
    {
        this->value = value;
        this->next = next;
    }
    void setNext(Node *x)
    {
        this->next = x;
    }
    void setValue(int val)
    {
        this->value = val;
    }
    Node *getnext()
    {
        return this->next;
    }
    int getValue()
    {
        return this->value;
    }
};

class LLrecursion
{
    Node *head = NULL;
    Node *tail = NULL;
    int size = 0;

    void insertRec(int val, int indx, Node *curr)
    {
        if (indx == 0)
        {
            Node *temp = new Node(val, curr);
            head = temp;
            size++;
            return;
        }
        else if (indx == 1)
        {
            Node *temp = new Node(val, curr->getnext());
            curr->setNext(temp);
            size++;
            return;
        }
        else
        {
            insertRec(val, indx - 1, curr->getnext());
        }
    }
    Node *insertRec2(int val, int index, Node *curr)
    {
        if (index == 0)
        {
            Node *temp = new Node(val, curr);

            size++;
            return temp;
        }
        if (curr == NULL)
        {
            if (index == 1)
            {
                Node *temp = new Node(val, curr);

                size++;
                return temp;
            }
            cout << " range error";
            return NULL;
        }
        Node *t = insertRec2(val, index--, curr->getnext());
        curr->setNext(t);
        return curr;
    }
    void displayRec(Node *curr)
    {
        if (curr == NULL)
        {
            cout << "END" << endl;
            return;
        }
        cout << curr->getValue() << "->";
        displayRec(curr->getnext());
    }

public:
    void display()
    {
        displayRec(head);
    }
    void insert(int val, int indx)
    {
        head = insertRec2(val, indx, head);
        //    insertRec(val, indx, head);
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
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }
        ListNode *temp = head;
        while (temp->val == head->val)
        {
            temp = temp->next;
            if (temp == NULL)
                break;
        }
        head->next = deleteDuplicates(temp);

        return head;
    }
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *curr = new ListNode(-1);
        ListNode *head = curr;
        while (list1 != NULL || list2 != NULL)
        {
            if (list1 == NULL)
            {
                curr->next = list2;
                break;
            }
            if (list2 == NULL)
            {
                curr->next = list1;
                break;
            }

            if (list1->val > list2->val)
            {
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
            }
            else
            {
                curr->next = list1;
                curr = curr->next;
                list1 = list1->next;
            }
        }
        head = head->next;
        return head;
    }
    bool hasCycle(ListNode *head)
    {
        // map<ListNode*,bool> isVisited;
        // ListNode* temp=head;

        // while(temp!=NULL){
        //     if(isVisited[temp]==true){
        //         return true;
        //     }
        //     isVisited[temp]=true;
        //     temp=temp->next;
        // }

        ListNode *fast = head;
        ListNode *slow = head;
        bool startCount = false;
        int count = 0;
        while (fast != NULL && fast->next != NULL)
        {
            if (fast == slow)
            {
                ListNode *temp = slow;
                do
                {
                    temp = temp->next;
                    count++;
                } while (temp != slow);
                return true;
                // startCount = true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        // if (startCount)
        // {
        //     count++;
        // }
        return false;
    }
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        int count = 0;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                ListNode *temp = slow;
                do
                {
                    temp = temp->next;
                    count++;
                } while (temp != slow);

                break;
            }
        }
        if (count == 0)
        {
            return NULL;
        }
        fast = slow = head;
        for (int i = 0; i < count; i++)
        {
            slow = slow->next;
        }
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    int getSquare(int x)
    {
        int sq = 0;
        while (x > 0)
        {
            sq = sq + pow(x % 10, 2);
            x = x / 10;
        }
        return sq;
    }

    bool isHappy(int n)
    {
        int s = n;
        int f = n;
        int cur;
        int nextCurr;

        while (s != 1 && f != 1)
        {
            s = getSquare(s);
            f = getSquare(getSquare(f));

            if (s == f)
            {
                if (s == 1 || f == 1)
                    return true;
                return false;
            }
        }
        return true;
    }
    ListNode *middleNode(ListNode *head)
    {
        ListNode *s = head;
        ListNode *f = head;

        while (f != NULL && f->next != NULL)
        {
            f = f->next->next;
            s = s->next;
        }
        return s;
    }
    void middleNode2(ListNode *head, ListNode **a, ListNode **b)
    {
        ListNode *s = head;
        ListNode *f = head;

        while (f != NULL && f->next != NULL)
        {
            f = f->next->next;
            s = s->next;
        }
        *b = s;
        s->next = NULL;
        *a = head;
    }

    ListNode *mergesort(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *back;
        ListNode *front;
        middleNode2(head, &back, &front);
        // back = mid->next;
        // mid->next = NULL;

        ListNode *left = mergesort(front);
        ListNode *right = mergesort(back);

        return mergeTwoLists(left, right);
    }

    ListNode *sortList(ListNode *head)
    {
        return mergesort(head);
    }
};
class mergeLL
{

public:
ListNode *middle(ListNode *head)
    {
        ListNode *f = head->next;
        ListNode *s = head;

        while (f != NULL && f->next != NULL)
        {
            s = s->next;
            f = f->next->next;
        }
        cout<<s->val;

        return s;
    }
    ListNode *mergeList(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        ListNode *curr = new ListNode(-1);
        ListNode *ans = curr;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val > list2->val)
            {
                curr->next = list2;
                curr = list2;
                list2->next = list2->next;
            }
            else
            {
                curr->next = list1;
                curr =list1;
                list1 = list1->next;
            }
        }
        while (list1 != NULL)
        {
            curr->next = list1;
            curr = list1;
            list1 = list1->next;
        }

        while (list2 != NULL)
        {
            curr->next = list2;
            curr = curr->next;
            list2->next = list2->next;
        }
        ans = ans->next;
        return ans;
    }
    ListNode *mergesort(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *mid = middle(head);
        
        ListNode *front = head;
        ListNode *back = mid->next;
        mid->next = NULL;
        while(front!=NULL){
            cout<<front->val<<endl;
            front=front->next;
        }

        ListNode *right = mergesort(front);
        ListNode *left = mergesort(back);

       ListNode* result= mergeList(right, left);
       return result;
        // return head;
    }
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};

class Solution {
     void helper(ListNode* first, ListNode* sec, ListNode* &tail, bool flag){
        if(first == NULL || sec == NULL) return;
        
        first->next = sec->next;
        first = first->next;
        sec->next = NULL;
         if(flag && first) tail = first;
        helper(sec, first, tail, !flag);
        
    }
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode* tail = NULL;
        helper(head, head->next, tail, true);
        tail->next = head->next;
        return head;
    }
};

//MERGE SORT MEHNAT VALI 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solutionmergesort {
public:
 ListNode *middle(ListNode *head)
    {
        ListNode *f = head->next;
        ListNode *s = head;

        while (f != NULL && f->next != NULL)
        {
            s = s->next;
            f = f->next->next;
        }
  

        return s;
    }
    ListNode *mergeList(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        ListNode *curr = new ListNode(-1);
        ListNode *ans = curr;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val > list2->val)
            {
                curr->next = list2;
                curr = list2;
                list2 = list2->next;
            }
            else
            {
                curr->next = list1;
                curr =list1;
                list1 = list1->next;
            }
        }
        while (list1 != NULL)
        {
            curr->next = list1;
            curr = list1;
            list1 = list1->next;
        }

        while (list2 != NULL)
        {
            curr->next = list2;
            curr = curr->next;
            list2= list2->next;
        }
        ans = ans->next;
        return ans;
    }
    ListNode *mergesort(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *mid = middle(head);
       
        ListNode *front = head;
        ListNode *back = mid->next;
        mid->next = NULL;
        ListNode* x =front;
        ListNode* y=back;
      
         
        ListNode *right = mergesort(x);
        ListNode *left = mergesort(y);
       ListNode* result= mergeList(right, left);

        
       
        return result;
    }
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};

class BubbuleLL{

public:

};



int main()
{
    LLrecursion list;
    Solution s;
    // cout << s.getSquare(37) << endl;
    list.insert(12, 0);
    list.insert(15, 1);
    list.display();
    // list.Display();
    // list.insertEnd(11);
    // list.Display();
    // // list.insertAtMid(12);
    // // list.insertAtMid(17);
    // // list.insertAtMid(19);
    // list.insertat(45,4);
    // list.Display();
    // // list.getPrvNodeByValue(11);
    // list.insertFirst(5);
    // list.insertFirst(8);
    // list.insertFirst(9);
    // list.insertFirst(3);
    // list.insertEnd(11);
    // list.insertEnd(17);
    // list.insertEnd(19);
    // list.insertEnd(15);
    // list.insertat(44, 4);
    // list.insertat(47, 10);
    // list.insertat(13, 12);

    // list.Display();
    // list.deleteFirst();
    // list.deleteEnd();
    // list.Display();
    // list.deleteIndex(3);

    // list.deleteByValue(19);
    // list.deleteIndex(18);
    // list.deleteByValue(50);
    // list.Display();

    return 0;
}