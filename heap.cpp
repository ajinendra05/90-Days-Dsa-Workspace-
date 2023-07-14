#include <bits/stdc++.h>

using namespace std;

class heap
{
public:
    int arr[100];
    int size = 0;

    // heap(int size){
    //     arr=new int(size);
    //     this->size=size;
    // }

    // O(log(n))
    void insert(int val)
    {
        size = size + 1;

        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int par = index / 2;

            if (arr[par] < arr[index])
            {
                swap(arr[par], arr[index]);
                index = par;
            }
            else
            {
                break;
            }
        }
    }

    //log(n)
     void heapify(int arr[], int size, int index)
    {   int largest=index;
        int leftChild = index * 2;
        int rightChild = index * 2 + 1;

        if(leftChild<size&&arr[largest]<arr[leftChild])
            largest=leftChild;
        if(rightChild<size&&arr[largest]<rightChild)
            largest=rightChild;
        
        if(largest!=index){
            swap(arr[largest],arr[index]);
            heapify(arr,size,largest);
        }
        return;
    }
    void heapify2(int arr[], int size, int i)
    {   int index=i;
        int leftChild = i * 2;
        int rightChild = i * 2 + 1;

        // if(arr[i]<arr[leftChild])
        //     i=leftChild;
        // if(arr[i]<rightChild)
        //     i=rightChild;
        
       
        if (leftChild <= size && rightChild <= size && arr[i] < arr[leftChild] && arr[i] < arr[rightChild])
        {
            if (arr[leftChild] > arr[rightChild])
            {
                swap(arr[i], arr[leftChild]);
                i = leftChild;
            }
            else
            {
                swap(arr[i], arr[rightChild]);
                i = rightChild;
            }
        }
        else if (leftChild <= size && arr[i] < arr[leftChild])
        {
            swap(arr[i], arr[leftChild]);
            i = leftChild;
        }
        else if (rightChild <= size && arr[i] < arr[rightChild])
        {
            swap(arr[i], arr[rightChild]);
            i = rightChild;
        }


        if(i!=index){
            heapify2(arr,size,i);
        }
        return;
    }
    
    // O(log(n))
    void deletion()
    {
        if (size == 0)
        {
            cout << "underFlow";
            return;
        }

        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {   
            int largest=i;
            int lefftChild = 2 * i;
            int rightChild = 2 * i + 1;

            if(lefftChild<=size&&arr[largest]<arr[lefftChild])
                largest=lefftChild;
            if(rightChild<=size&&arr[largest]<arr[rightChild])  
                largest=rightChild;
            
            if(largest!=i){
                swap(arr[i],arr[largest]);
                i=largest;
            }else{
                break;
            }
        }
    }
    void deletion2()
    {
        if (size == 0)
        {
            cout << "underFlow";
            return;
        }

        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int lefftChild = 2 * i;
            int rightChild = 2 * i + 1;

            if (lefftChild <= size && rightChild <= size && arr[i] < arr[lefftChild] && arr[i] < arr[rightChild])
            {
                if (arr[lefftChild] > arr[rightChild])
                {
                    swap(arr[i], arr[lefftChild]);
                    i = lefftChild;
                }
                else
                {
                    swap(arr[i], arr[rightChild]);
                    i = rightChild;
                }
                continue;
            }
            if (lefftChild <= size && arr[i] < arr[lefftChild])
            {
                swap(arr[i], arr[lefftChild]);
                i = lefftChild;
                continue;
            }
            if (rightChild <= size && arr[i] < arr[rightChild])
            {
                swap(arr[i], arr[rightChild]);
                i = rightChild;
                continue;
            }
            break;
        }
    }
    void display()
    {

        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
    }
};

 void heapify(int arr[], int size, int index)
    {   int largest=index;
        int leftChild = index * 2;
        int rightChild = index * 2 + 1;

        if(leftChild<=size&&arr[largest]<arr[leftChild])
            largest=leftChild;
        if(rightChild<=size&&arr[largest]<arr[rightChild])
            largest=rightChild;
        
        if(largest!=index){
            swap(arr[largest],arr[index]);
            heapify(arr,size,largest);
        }
        return;
    }
void heapSort(int arr[],int size){
   int n=size;

   while(n>1){
    swap(arr[1],arr[n]);
    n--; 
    heapify(arr,n,1);         //log(n) always
   }
}
void buildHeap(int arr[],int size){
    for(int i=size/2;i>0;i--){
        heapify(arr,size,i);
    }
}
int main()
{
    heap h;
    h.insert(5);
    h.insert(15);
    h.insert(9);
    h.insert(14);
    h.insert(12);
    h.insert(40);
    h.display();
    h.deletion();
    cout << endl;
    h.display();
    int arr[]={0,5,8,6,1,7,3,9};
    // buildHeap(arr,7);
    // heapSort(arr,7);
    // cout<<endl;
    // for(int i=0;i<=7;i++){
    //     cout<<arr[i]<<" ";
    // }



    //STL
    
    //max heap
    priority_queue<int> pq;
    for(int i=0;i<=7;i++){
        pq.push(arr[i]);
    }
    cout<<endl<<"yaha se STL "<<endl;
     
    for(int i=0;i<=7;i++){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    

    //min heap
    cout<<endl;
    priority_queue<int,vector<int>, greater<int>> minpq;
    for(int i=0;i<=7;i++){
        minpq.push(arr[i]);
    }

    for(int i=0;i<=7;i++){
        cout<<minpq.top()<<" ";
        minpq.pop();
    }
    return 0;
}