#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int value;
    Node *next;
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
    // void display()
    // {
    //     cout << this->value;
    // }
};
class Node2
{
public:
    int value;
    Node2 *next;
    Node2 *prev;
    Node2(int value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
    Node2(int value, Node2 *next, Node2 *prev)
    {
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
};
class DLL
{
    Node2 *head;
    Node2 *tail;
    int size;

public:
    DLL()
    {
        this->size = 0;
        head = NULL;
        tail = NULL;
    }
    Node2 *getNode(int index)
    {
        if (size <= 0)
        {
            cout << "EMPTY";
            return NULL;
        }
        if (index >= this->size)
        {
            cout << "\n rnage error";
            return NULL;
        }
        Node2 *temp = this->head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp;
    }
    Node2 *getNodeByValue(int value)
    {
        if (size <= 0)
        {
            cout << "EMPTY";
            return NULL;
        }
        // if (this->head == NULL)
        //     return NULL;
        Node2 *temp = this->head;
        while (temp->value != value)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                cout << "\n value does not exist";
                return NULL;
            }
        }

        return temp;
    }
    // Node *getPrvNodeByValue(int value)
    // {
    //     Node *temp = this->head;
    //     while (temp->next->value != value)
    //     {
    //         temp = temp->next;
    //         if (temp->next == NULL)
    //         {
    //             cout << "\n value does not exist";
    //             return NULL;
    //         }
    //     }

    //     return temp;
    // }
    void insertFirst(int value)
    {
        Node2 *temp = new Node2(value, this->head, NULL);
        if (this->size == 0)
        {
            this->head = temp;
            this->tail = this->head;
            size++;
            return;
        }
        this->head->prev = temp;
        this->head = temp;

        // Node temp(value,this->head);
        // head = &temp;

        size++;
    }
    void insertEnd(int value)
    {

        if (this->size == 0)
        {
            this->insertFirst(value);
            return;
            // this->head = temp;
            // this->tail = head;
        }
        Node2 *temp = new Node2(value, NULL, this->tail);
        this->tail->next = temp;
        this->tail = temp;

        size++;
    }
    void insertat(int value, int index)
    {

        if (index == 0)
        {
            insertFirst(value);
            return;
        }
        if (index == size)
        {
            insertEnd(value);
            return;
        }

        if (index > this->size)
        {
            cout << "RANGE ERROR";
            return;
        }

        Node2 *temp = this->head;
        //  for (int i = 1; i < index-1; i++)
        // {
        //     temp = temp->next;
        // }

        // Inser at nth index
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        Node2 *temp2 = new Node2(value, temp, temp->prev);
        temp->prev->next = temp2;

        temp->prev = temp2;

        size++;
    }
    void Display()

    {
        if (this->head == NULL)
        {
            cout << "empty" << endl;
            return;
        }

        Node2 *temp = this->head;
        cout << endl
             << endl;
        while (temp != NULL)
        {

            cout
                << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "END";
    }
    void deleteFirst()
    {
        Node2 *temp = this->head;
        if (this->size == 1)
        {

            this->head = NULL;
            this->tail = NULL;
            cout << "\n deleted value :" << temp->value;
            delete (temp);
            return;
        }
        this->head = head->next;
        this->head->prev = NULL;
        cout << "\n deleted value :" << temp->value;
        delete (temp);
        this->size--;
    }
    void deleteEnd()
    {
        if (size <= 0)
        {
            cout << "EMPTY";
            return;
        }
        Node2 *temp = this->tail;
        if (this->size == 1)
        {

            this->head = NULL;
            this->tail = NULL;
            cout << "\n deleted value :" << temp->value;
            delete (temp);
            return;
        }
        // Node2 *temp2 = getNode((this->size) - 2);

        this->tail = this->tail->prev;
        this->tail->next = NULL;

        cout << "\n deleted value :" << temp->value;
        delete (temp);
        this->size--;
    }
    void deleteIndex(int index)
    {

        if (index == 0)
        {

            deleteFirst();
            return;
        }
        if (index == this->size - 1)
        {
            deleteEnd();
            return;
        }
        if (index >= this->size)
        {

            cout << "\n Range ERROR";
            return;
        }
        Node2 *temp = getNode(index);

        // Node2 *temp2 = temp->next;
        // Node2 *temp2 = temp->prev;
        // Node2 *temp3 = temp->next;
        // temp2->next = temp3;
        // temp3->prev = temp2;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        // temp->next = temp2->next;
        // temp->next=temp->next->next;
        cout << "\n deleted value :" << temp->value;
        delete (temp);
        this->size--;
    }
    void deleteByValue(int value)
    {
        Node2 *temp = getNodeByValue(value);
        if (temp == NULL)
        {
            return;
        }
        if (temp->prev == NULL)
        {
            deleteFirst();
            return;
        }
        if (temp->next == NULL)
        {
            deleteEnd();
            return;
        }
        // Node2 *temp2 = temp->prev;
        // Node2 *temp3 = temp->next;
        // temp2->next = temp3;
        // temp3->prev = temp2;

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        cout << "\n deleted value :" << temp->value;
        delete (temp);
    }
};
class LL
{
    Node *head;
    Node *tail;
    int size;
    Node *currHead;

public:
    LL()
    {
        this->size = 0;
        head = NULL;
        tail = NULL;
    }
    Node *getNode(int index)
    {
        if (index >= this->size && index < 0)
        {
            cout << "\n rnage error";
            return NULL;
        }
        Node *temp = this->head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp;
    }
    Node *getNodeByValue(int value)
    {
        if (size <= 0)
            return NULL;
        Node *temp = this->head;
        while (temp->value != value)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                cout << "\n value does not exist";
                return NULL;
            }
        }

        return temp;
    }
    Node *getPrvNodeByValue(int value)
    {
        if (size <= 1)
            return NULL;
        Node *temp = this->head;

        while (temp->next->value != value)
        {
            temp = temp->next;
            if (temp->next == NULL)
            {
                cout << "\n value does not exist";
                return NULL;
            }
        }

        return temp;
    }
    void insertFirst(int value)
    {
        Node *temp = new Node(value, this->head);
        this->head = temp;

        // Node temp(value,this->head);
        // head = &temp;
        if (this->size == 0)
        {
            this->tail = this->head;
        }
        size++;
    }
    void insertEnd(int value)
    {

        if (this->size == 0)
        {
            this->insertFirst(value);
            return;
            // this->head = temp;
            // this->tail = head;
        }
        Node *temp = new Node(value);
        this->tail->next = temp;
        this->tail = temp;

        size++;
    }
    void insertat(int value, int index)
    {

        if (index == 0)
        {
            insertFirst(value);
            return;
        }
        if (index == size)
        {
            insertEnd(value);
            return;
        }

        if (index > this->size)
        {
            cout << "RANGE ERROR";
            return;
        }

        Node *temp = this->head;
        //  for (int i = 1; i < index-1; i++)
        // {
        //     temp = temp->next;
        // }

        // Inser at nth index
        for (int i = 1; i < index; i++)
        {
            temp = temp->next;
        }
        Node *temp2 = new Node(value, temp->next);

        temp->next = temp2;

        size++;
    }
    void insertAtMid(int value)
    {
        if (size == 0 || size == 1)
        {
            insertFirst(value);
            return;
        }
        Node *temp = this->head;

        // Inser at nth index
        for (int i = 1; i < size / 2; i++)
        {
            temp = temp->next;
        }
        Node *temp2 = new Node(value, temp->next);

        temp->next = temp2;

        size++;
    }
    void Display()

    {
        if (this->head == NULL)
        {
            cout << "empty" << endl;
            return;
        }

        Node *temp = this->head;
        cout << endl
             << endl;
        while (temp != NULL)
        {

            cout
                << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "END";
    }
    void deleteFirst()
    {
        if (size <= 0)
        {
            cout << "EMPTY";
            return;
        }
        Node *temp = this->head;

        if (this->size == 1)
        {

            this->head = NULL;
            this->tail = NULL;
            cout << "\n deleted value :" << temp->value;
            delete (temp);
            return;
        }
        this->head = head->next;

        cout << "\n deleted value :" << temp->value;
        delete (temp);
        this->size--;
    }
    void deleteEnd()
    {
        if (size <= 0)
        {
            cout << "EMPTY";
            return;
        }
        Node *temp = this->tail;
        if (this->size == 1)
        {

            this->head = NULL;
            this->tail = NULL;
            cout << "\n deleted value :" << temp->value;
            delete (temp);
            return;
        }
        Node *temp2 = getNode((this->size) - 2);

        this->tail = temp2;
        temp2->next = NULL;

        cout << "\n deleted value :" << temp->value;
        delete (temp);
        this->size--;
    }
    void deleteIndex(int index)
    {
        if (size <= 0)
        {
            cout << "EMPTY";
            return;
        }
        if (index == 0)
        {
            deleteFirst();
            return;
        }
        if (index == this->size - 1)
        {
            deleteEnd();
            return;
        }
        if (index >= this->size)
        {
            cout << "\n Range ERROR";
            return;
        }
        Node *temp = getNode(index - 1);

        Node *temp2 = temp->next;

        temp->next = temp2->next;
        // temp->next=temp->next->next;
        cout << "\n deleted value :" << temp2->value;
        delete (temp2);
        this->size--;
    }
    void deleteByValue(int value)
    {
        if (size <= 0)
        {
            cout << "EMPTY";
            return;
        }
        Node *temp = getPrvNodeByValue(value);
        if (temp == NULL)
        {
            return;
        }
        Node *temp2 = temp->next;

        temp->next = temp2->next;
        cout << "\n deleted value :" << temp2->value;
        delete (temp2);
    }

    // Questions

    void reverselist()
    {
        // reverseit();
        // reverseBetween(head, 1, 5);
        reorderList(this->head);
    }
    void reverseLL(Node *curr)
    {
        if (curr == tail)
        {
            this->head = curr;
            curr->next = NULL;
            return;
        }
        else
        {
            reverseLL(curr->next);
            tail->next = curr;
            tail = curr;
            tail->next = NULL;
            return;
        }
    }
    Node *reverseLLifTailNotGiven(Node *curr)
    {
        if (curr->next == NULL)
        {
            this->head = curr;
            curr->next = NULL;
            return curr;
        }
        else
        {
            Node *afterNode = reverseLLifTailNotGiven(curr->next);
            afterNode->next = curr;
            // tail=curr;
            curr->next = NULL;
            return curr;
        }
    }

    // reverse without recursion
    void reverseit()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = curr->next;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    Node *reverseBetween(Node *head, int left, int right)
    {
        Node *prev1 = NULL;
        Node *curr = head;

        for (int i = 1; i < left; i++)
        {
            prev1 = curr;
            curr = curr->next;
        }
        Node *start = curr;
        Node *prev = NULL;
        Node *next;
        while (right - left >= 0)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            right--;
        }
        start->next = next;
        if (left == 1)
        {
            cout << "me" << prev->value << prev->next->value;
            return prev;
        }
        else
        {
            prev1->next = prev;
        }
        return head;
    }

    Node *travarseandreorder(Node *curr)
    {
        if (curr->next == NULL)
        {
            return curr;
        }
        Node *retNode = travarseandreorder(curr->next);
        if (retNode == NULL)
        {
            return NULL;
        }
        Node *temp = currHead->next;
        currHead->next = retNode;
        retNode->next = temp;
        currHead = temp;
        if (currHead == curr || currHead->next == curr)
        {
            curr->next = NULL;

            return NULL;
        }
        return curr;
    }
    void reorderList(Node *head)
    {
        currHead = head;
        travarseandreorder(head);
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

class LLQUESTION
{
    vector<int> forwNum;
    vector<int> backNum;
    ListNode *currHead;

public:
    // return 2nd middle if even
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

    // return 1st middle of even MAIN MIDDLE
    ListNode *middleNodeMain(ListNode *head)
    {
        ListNode *s = head;
        ListNode *f = head->next;

        while (f != NULL && f->next != NULL)
        {
            f = f->next->next;
            s = s->next;
        }
        return s;
    }
    // return prev of null if odd or 1st middle if even
    ListNode *prevMiddleNode(ListNode *head)
    {
        ListNode *s = head;
        ListNode *f = head->next;
        f = f->next->next;
        while (f != NULL && f->next != NULL)
        {
            f = f->next->next;
            s = s->next;
        }
        return s;
    }
    
    // reversion ll
    // main
    ListNode* reverseLL(ListNode* curr){
        if(curr == NULL || curr->next == NULL) return curr;
        
        ListNode* newHead = reverseLL(curr->next);
        
        curr->next->next = curr;
        curr->next = NULL;
        
        return newHead;
    }  
    ListNode* reverseWithoutRec(ListNode* head){
        ListNode *curr, *next, *prev;
        curr = head;
        prev = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode *reversionLL(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *newHead = reversionLL(head->next);

        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
    
    // other also
    void reverseLLrecursion(ListNode *curr, ListNode **head, ListNode *prev)
    {
        if (curr == NULL)
        {
            *head = prev;
            return;
        }
        reverseLLrecursion(curr->next, head, curr);
        curr->next = prev;
    }
    ListNode *reverseLLrecursion2(ListNode *curr, ListNode **head)
    {

        if (curr == NULL || curr->next == NULL)
        {
            *head = curr;
            return curr;
        }

        ListNode *afterNode = reverseLLrecursion2(curr->next, head);
        afterNode->next = curr;
        curr->next = NULL;
        return curr;
    }
    ListNode *reverseit(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = curr->next;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
    
    //reverse between given range
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *prev1 = NULL;
        ListNode *curr = head;

        for (int i = 1; i < left; i++)
        {
            prev1 = curr;
            curr = curr->next;
        }
        ListNode *start = curr;
        ListNode *prev = NULL;
        ListNode *next;
        while (right - left >= 0)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            right--;
        }
        start->next = next;
        if (left == 1)
        {
            return prev;
        }
        else
        {
            prev1->next = prev;
        }
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head)   return NULL;
        if(!head->next) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;

        for(int i = 0; i < left - 1; i++)    prev = prev->next;
        ListNode *curr = prev->next;

        for(int i = 0; i < right - left; i++)
        {
            ListNode *forw = curr->next;
            curr->next = forw->next;
            forw->next = prev->next;
            prev->next = forw;
        }
        return dummy->next;

        
        
    }

    // merge a sorted linked list
    //inplace
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        if(list1->val > list2->val) swap(list1, list2);
        ListNode* head = list1;

        while(list1 && list2){
            ListNode* tmp = NULL;
            
            while(list1 && list1->val <= list2->val){
                tmp = list1;
                list1 = list1->next;
            }
            tmp->next = list2;
            swap(list1, list2);
        }
        
        return head;
    }
    // merge any linked list
    void mergeList(ListNode* head1, ListNode* head2){
        ListNode* temp1, *temp2;
        while(head1 && head2){
            temp1 = head1->next;
            head1->next = head2;
            head1 = temp1;
            swap(head1, head2);
        }
    }
    // 2nd way to merge them
        void mergeList2(ListNode* head1, ListNode* head2){
        ListNode* temp;
        while(head1 && head2){
            temp = head1->next;
            head1->next = head2;
            head1 = temp;
            
            temp = head2->next;
            head2->next = head1;
            head2 = temp;
            
        }
    }
    // add two numbers
    class Solution {
    ListNode* addNumbers(ListNode* l1, ListNode* l2, int rem) {
        if(l1 == NULL && l2 == NULL && rem == 0) return NULL;
        int sum = 0;
        if(l1 != NULL){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL){
            sum += l2->val;
            l2 = l2->next;
        }
        sum += rem;
        rem = sum / 10;
        ListNode* curr = new ListNode(sum % 10);
        curr->next = addNumbers(l1, l2, rem);
        return curr;
        
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addNumbers(l1, l2, 0);
    }
};
class Solution {
 
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode(1);
        ListNode* temp = dummy;
        int rem = 0, sum = 0;
        while(!(l1 == NULL && l2 == NULL && rem == 0)){
            
            sum = 0;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += rem;
            rem = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }
        return dummy->next;
    }
};

    bool hasCycle(ListNode *head)
    {

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

        return false;
    }
    ListNode *detectCycleStartingNode(ListNode *head)
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
    ListNode *travarseandreorder(ListNode *curr)
    {
        if (curr->next == NULL)
        {
            return curr;
        }
        ListNode *retNode = travarseandreorder(curr->next);
        if (retNode == NULL)
        {
            return NULL;
        }
        ListNode *temp = currHead->next;
        currHead->next = retNode;
        retNode->next = temp;
        currHead = temp;
        if (currHead == curr || currHead->next == curr)
        {
            curr->next = NULL;

            return NULL;
        }
        return curr;
    }
    void reorderList(ListNode *head)
    {
        if (head->next == NULL || head->next->next == NULL)
            return;
        currHead = head;
        travarseandreorder(head);
    }

    bool calcNum(ListNode *curr)
    {
        if (curr == NULL)
        {
            return true;
        }
        forwNum.push_back(curr->val);

        bool x = calcNum(curr->next);
        if (x == false)
            return false;
        if (forwNum[0] == curr->val)
        {
            forwNum.erase(forwNum.begin());
            return x && true;
        }
        return false;
    }
    bool isPalindrome(ListNode *head)
    {
        // return calcNum(head);

        ListNode *mid = middleNode(head);

        ListNode *prev = NULL;
        ListNode *curr = mid;
        ListNode *next = curr->next;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode *secHead = prev;

        ListNode *curr1 = head;
        ListNode *cur2 = secHead;
        while (curr1 != mid)
        {
            if (curr1->val != cur2->val)
            {
                prev = NULL;
                curr = mid;
                next = curr->next;

                while (curr != NULL)
                {
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }
                return false;
            }
            cur2 = cur2->next;
            curr1 = curr1->next;
        }
        prev = NULL;
        curr = mid;
        next = curr->next;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return true;
    }
    // recursio reverse ll

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        int rem = count % k;
        temp = head;
        for (int i = 1; i <= (count - rem); i += k)
        {
            temp = reverseBetween(temp, i, i + k - 1);
        }

        return temp;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        if (count <= 1)
        {
            return head;
        }
        int totake = k % count;

        if (totake == 0)
        {
            return head;
        }
        temp = head;
        for (int i = 1; i < (count - totake); i++)
        {
            temp = temp->next;
        }
        ListNode *start = temp->next;
        temp->next = NULL;
        temp = start;
        while (temp->next != NULL)
        {

            temp = temp->next;
        }
        temp->next = head;
        return start;
    }

    int numComponents0(ListNode *head, vector<int> &nums)
    {

        if (nums.size() == 1)
            return 1;
        int n = nums.size();
        ListNode *temp = head;
        int i = n;
        bool flag = false;
        int count = 0;

        while (temp != NULL)
        {
            if (i <= 0)
            {
                break;
            }

            while (temp->val == nums[n - i])
            {
                flag = true;
                temp = temp->next;
                i--;
                if (temp == NULL)
                    break;
            }
            if (flag == true)
            {
                count++;
                flag = false;
                continue;
            }
            if (temp == NULL)
                break;
            temp = temp->next;
        }
        return count;
    }
    int numComponents(ListNode *head, vector<int> &nums)
    {
        map<int, int> nodeMap;
        int count = 0;
        int n = nums.size();
        map<int, bool> check;

        for (int i = 0; i < n; i++)
        {
            check[nums[i]] = true;
        }
        ListNode *prev = head;
        while (head->next != NULL)
        {
            if (check[head->val] == true && check[head->next->val] == true)
            {
                count++;
            }
            prev = head;
            head = head->next;
        }

        // for (int i = 1; i < n; i++)
        // {
        //     if (nums[i] == next)
        //     {
        //         next = nodeMap[nums[i]];
        //     }
        //     else
        //     {
        //         count++;
        //         next = nodeMap[nums[i]];
        //     }
        // }
        return count;
    }

    int numComponents2(ListNode *head, vector<int> &nums)
    {
        ListNode *curr = head;
        int ans = 0;
        set<int> s;
        for (auto x : nums)
            s.insert(x);

        for (curr; curr != NULL; curr = curr->next)
        {
            if (s.find(curr->val) != s.end())
            {
                if (curr->next == NULL || s.find(curr->next->val) == s.end())
                    ans++;
            }
        }
        return ans;
    }

    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return head;
        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *ts = second;
        ListNode *curr = head->next->next;

        while (curr != NULL)
        {
            first->next = curr;
            first = first->next;

            ts->next = curr->next;

            ts = ts->next;
            if (curr->next == NULL || curr->next->next == NULL)
            {

                break;
            }
            else
            {
                curr = curr->next->next;
            }
        }
        first->next = second;

        return head;
    }
    int getRandom()
    {
    }

    TreeNode *head;
    TreeNode *present;
    TreeNode *traverse(TreeNode *curr)
    {

        if (curr == NULL)
        {
            return;
        }
        // TreeNode *temp = curr;
        // temp->left = NULL;
        // temp->right = NULL;
        // present = temp;
        // present = present->right;
        TreeNode *temp = curr->right;

        traverse(curr->left);

        traverse(curr->right);
    }
    void flatten(TreeNode *root)
    {
        head = new TreeNode(2);
        present = head;
        present = present->right;
        traverse(root);
        root = head->right;
    }

    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ans;
        int size = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }
        temp = head;
        ListNode *temp2;
        if (k >= size)
        {
            for (int i = 0; i < size; i++)
            {
                temp2 = new ListNode(temp->val);

                ans.push_back(temp2);

                temp = temp->next;
            }
            for (int i = size; i < k; i++)
            {

                ans.push_back(NULL);
            }
            return ans;
        }
        int div = size / k;
        int rem = size % k;
        int curSize = div;
        temp = head;
        ListNode *temp3;
        for (int i = 0; i < k; i++)
        {
            if (rem > 0)
            {
                curSize = div + 1;
            }
            else
            {
                curSize = div;
            }
            temp2 = temp;
            for (int i = 1; i < curSize; i++)
            {

                temp = temp->next;
            }
            temp3 = temp->next;
            temp->next = NULL;
            ans.push_back(temp2);
            temp = temp3;
            rem--;
        }
        return ans;
    }

    ListNode *traverseAndAdd(ListNode *curr)
    {
        if (curr->next == NULL)
        {
            return curr;
        }

        ListNode *afterNode = traverseAndAdd(curr->next);

        if (afterNode->val > curr->val)
        {
            return afterNode;
        }
        else
        {
            curr->next = afterNode;
            return curr;
        }
    }
    ListNode *removeNodes(ListNode *head)
    {
        return traverseAndAdd(head);
    }
    ListNode *removeZeroSumSublists0(ListNode *head)
    {
        stack<ListNode *> s;
        ListNode *temp = head;
        s.push(temp);
        temp = temp->next;
        while (temp)
        {

            if (((s.top()->val) + temp->val) == 0)
            {
                s.pop();
                if (s.empty())
                {
                    head = temp->next;
                    if (temp->next == NULL)
                    {
                        break;
                    }
                    else
                    {
                        temp = temp->next;
                        s.push(temp);
                        temp = temp->next;
                        continue;
                    }
                }
                s.top()->next = temp->next;
                temp = temp->next;
            }
            else
            {
                s.push(temp);
                temp = temp->next;
            }
        }
        return head;
    }

    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *tail = head;
        int sum = 0;
        int round = 0;
        while (tail != NULL)
        {
            while (curr != NULL)
            {
                sum = sum + curr->val;
                if (sum == 0)
                {
                    if (round == 0)
                    {
                        head = curr->next;
                    }
                    else
                    {
                        tail->next = curr->next;
                    }
                }
                curr = curr->next;
            }
            if (round == 0)
                head = tail;
            if (round != 0)
            {
                head = tail;
                tail = tail->next;
            }
            round++;

            if (tail)
                curr = tail->next;
            sum = 0;
        }
        return head;
    }

    ListNode *mergeListss(ListNode *head1, ListNode *head2)
    {

        ListNode *m = new ListNode(-1);
        ListNode *head = m;
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->val > head2->val)
            {
                m->next = head1;
                m = m->next;
                head1 = head1->next;
            }
            else
            {
                m->next = head2;
                m = m->next;
                head2 = head2->next;
            }
        }
        if (head1 != NULL)
        {
            while (head1 != NULL)
            {
                m->next = head1;
                m = m->next;
                head1 = head1->next;
            }
        }
        if (head2 != NULL)
        {
            while (head2 != NULL)
            {
                m->next = head2;
                m = m->next;
                head2 = head2->next;
            }
        }
        cout << m->val;

        return m->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *mergeList;
        if (lists.size() == 0)
            return NULL;
        mergeList = lists[0];

        for (int i = 1; i < lists.size(); i++)
        {
            mergeList = mergeListss(mergeList, lists[i]);
        }
        return mergeList;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head, *fast = head;
        for (int i = 1; i < n; i++)
        {
            fast = fast->next;
        }
        if (fast->next == NULL)
        {
            head = head->next;
            return head;
        }
        fast = fast->next;
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }

    vector<int> nextLargerNodes0(ListNode *head)
    {
        ListNode *temp = head;
        int currval = temp->val;
        int start = 0;
        int end = 0;
        vector<int> ans;
        while (temp != NULL)
        {
            if (temp->val > currval)
            {
                for (int i = start; i < end; i++)
                {
                    ans.push_back(temp->val);
                }
                start = end;
                currval = temp->val;
            }

            end++;
            temp = temp->next;
        }
        if ((start + 1) != end)
        {
            for (int i = start; i < end; i++)
            {
                ans.push_back(0);
            }
        }
        return ans;
    }

    vector<int> nextLargerNodes01(ListNode *head)
    {
        ListNode *start = head, *end = head;
        int count = 0;
        while (start != NULL)
        {
            start = start->next;
            count++;
        }
        vector<int> vect1(count - 1);
        start = head;
        int s = 0, e = 0;
        bool flag = false;

        while (start != NULL)
        {
            while (end != NULL)
            {
                if (end->val > start->val)
                {
                    // fill(vect1.begin() + s, vect1.begin() + (e), end->val);
                    start = end;
                    s = e;
                    break;
                }

                e++;
                end = end->next;
            }
            if (end == NULL)
            {
                start = start->next;
                end = start;
                s = e = (s + 1);
            }
        }
        return vect1;
    }
    vector<int> nextLargerNodes(ListNode *head)
    {
        ListNode *start = head, *end = head;
        vector<int> ans;

        while (start != NULL)
        {
            while (end != NULL)
            {
                if (end->val > start->val)
                {
                    ans.push_back(end->val);
                    break;
                }

                end = end->next;
            }
            if (end == NULL)
                ans.push_back(0);
            start = start->next;
            end = start;
        }
        return ans;
    }

    ListNode *partition0(ListNode *head, int x)
    {
        if (head == NULL)
            return head;
        ListNode *fast = head;
        ListNode *slow = NULL;
        ListNode *n1;
        if (fast->val < x)
        {
            slow = head;
        }

        while (fast->next != NULL)
        {
            if (fast->next->val < x)
            {
                n1 = fast->next;
                fast->next = n1->next;
                if (slow == NULL)
                {
                    n1->next = head;
                    slow = head = n1;
                }
                else
                {
                    n1->next = slow->next;
                    slow->next = n1;
                    slow = slow->next;
                }
                continue;
            }
            if (fast == NULL || fast->next == NULL)
                break;
            fast = fast->next;
        }
        return head;
    }

    ListNode *partition(ListNode *head, int x)
    {
        ListNode *temp = head;
        ListNode *left = new ListNode(0);
        ListNode *right = new ListNode(0);
        ListNode *d1 = left, *d2 = right;
        while (temp != NULL)
        {
            if (temp->val < x)
            {
                d1->next = temp;
                d1 = d1->next;
            }
            else
            {
                d2->next = temp;
                d2 = d2->next;
            }
            temp = temp->next;
        }
        d1->next = right->next;
        d2->next = NULL;

        return left->next;
    }
};
class BrowserHistory {
    class Node{
        
        public: 
        string url;
        Node* prev;
        Node* next;
        Node(string url){
            this->url = url;
            prev = NULL;
            next = NULL;
        }
    };
    Node* curr;
public:
    BrowserHistory(string homepage) {
        curr = NULL;
    }
    
    void visit(string url) {
        curr->next = new Node(url);
        curr->next->prev = curr;
    }
    
    string back(int steps) {
        Node* temp = curr;
        while(steps-- && temp->prev){
            temp = temp->prev;
        }
        if(!steps){
            curr = temp;
            return curr->url;
        }

        return "";
    }
    
    string forward(int steps) {
        Node* temp = curr;
        while(steps-- && temp->next){
            temp = temp->next;
        }
        if(!steps){
            curr = temp;
            return curr->url;
        }

        return "";
    }
};

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return head;
        Node *temp = head;
        map<Node *, Node *> randomNodes;
        Node *head2 = new Node(temp->val);
        Node *temp2 = head2;
        randomNodes[temp]=temp2;
        temp=temp->next;
        while (temp != NULL)
        {
            Node *x = new Node(temp->val);
            temp2->next = x;
            randomNodes[temp] = temp2->next;
            temp2 = temp2->next;
            temp = temp->next;
        }
        temp = head;
        temp2 = head2;
        while (temp != NULL)
        {
            temp2->random = randomNodes[temp->random];
            temp2 = temp2->next;
            temp = temp->next;
        }
        return head2;
    }
};*/

/* //flatten of ll
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        Node *curr = head, *tail = head, *child;
        stack<Node *> s;
        while (curr != NULL)
        {
            child = curr->child;

            if (child != NULL)
            {
                if (curr->next != NULL)
                {
                    s.push(curr->next);
                }
                curr->next = child;
                child->prev = curr;
                curr->child = nullptr;
            }
            if(curr->next==NULL&&!s.empty()){
              Node* x= s.top();
              s.pop();
              curr->next=x;
              x->prev=curr;



            }
            tail = curr;
            curr = curr->next;
        }
        return head;
    }
};



class Solution
{
    Node *flatten_rec(Node *head)
    {
        Node *curr = head;
        Node *tail = head;
        Node *child;
        Node *next;

        while (curr != NULL)
        {
            child = curr->child;
            next = curr->next;
            if (child != NULL)
            {
                tail = flatten_rec(child);
                tail->next = next;
                if (next != NULL)
                    next->prev = tail;
                curr->next = child;
                child->prev = curr;
                curr->child = nullptr;
                curr = tail;
            }
            else
            {
                curr = next;
            }
            if (curr != NULL)
                tail = curr;

            // if(curr!=NULL)tail=curr;
        }
        return tail;
    }

public:
    Node *flatten(Node *head)
    {
        flatten_rec(head);
        return head;
    }
};
*/
int main()
{
    LL list;
    list.Display();
    list.insertEnd(11);
    list.Display();
    // list.insertAtMid(12);
    // list.insertAtMid(17);
    // list.insertAtMid(19);
    list.insertat(45, 4);
    list.Display();
    // list.getPrvNodeByValue(11);
    list.insertFirst(5);
    list.insertFirst(8);
    list.insertFirst(9);
    list.insertFirst(3);
    list.insertEnd(11);
    list.insertEnd(17);
    list.insertEnd(19);
    list.insertEnd(15);
    list.insertat(44, 4);
    list.insertat(47, 10);
    list.insertat(13, 12);

    list.Display();
    list.reverselist();
    list.Display();
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