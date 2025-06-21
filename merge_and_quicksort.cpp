#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& arr, int start, int mid, int end)
{
    vector<int> temp;
    int i = start, j = mid + 1;

    while(i <= mid && j <= end)
    {
        if(arr[i] < arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while(i <= mid)
    {
        temp.push_back(arr[i++]);
    }

    while(j <= end)
    {
        temp.push_back(arr[j++]);
    }

    for(int k = 0 ; k < temp.size(); k++)
    {
        arr[start + k] = temp[k];
    }
}

void merge_sort(vector<int>& arr, int start, int end)
{
    if(start >= end) return;

    int mid = (start + end) / 2;

    merge_sort(arr,start,mid);
    merge_sort(arr,mid+1,end);
    merge(arr,start,mid,end);
}

int partition(vector<int>& arr, int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;
    for(int j = start; j < end; j++)
    {
        if(arr[j] <= pivot)
        {
            swap(arr[++i] , arr[j]);
        }
    }
    swap(arr[++i],arr[end]);
    return i;
}

void quicksort(vector<int>& arr, int start, int end)
{
    if(start >= end) return;

    int pivotindex = partition(arr,start,end);

    quicksort(arr,start,pivotindex - 1);
    quicksort(arr,pivotindex + 1,end);
}

void printarray(vector<int>& arr, int n){
    cout<<endl;
    cout<<"Array is : ";
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr;

    int n, choice, value;

    do
    {
        cout<<"\n--------------------------"<<endl;
        cout<<"1. add array"<<endl;
        cout<<"2. merge sort"<<endl;
        cout<<"3. quick sort"<<endl;
        cout<<"4. display"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1 :
                cout<<"Enter size of array : ";
                cin>>n;

                for(int i = 0; i < n; i++)
                {
                    cout<<"Enter value a["<<i<<"] : ";
                    cin>>value;
                    arr.push_back(value);
                }
                cout<<endl;
                break;
            case 2 :
                merge_sort(arr,0,arr.size() -1);
                cout<<"Array sorting using merge sort.";
                break;
            case 3 :
                quicksort(arr,0,arr.size() -1);
                cout<<"Array sorting using merge sort.";
                break;
            case 4 :
                printarray(arr,n);
                break;
            case 0 :
                cout<<"Exiting....!"<<endl;
                break;
            default:
                cout<<"Invalid choice!"<<endl;
                break;
        }
        
    } while (choice != 0);
    
    return 0;
}