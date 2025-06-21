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

int binarysearch(vector<int>& arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;

    while(start <= end)
    {
        int mid = (start + end) / 2;

        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

void display(vector<int> arr, int n)
{
    cout<<"sorted array : ";
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr;

    int n, target, choice, value, element;

    do
    {
        cout<<"\n--------------------------------"<<endl;
        cout<<"1 . add array "<<endl;
        cout<<"2 . merge sort"<<endl;
        cout<<"3 . binary search "<<endl;
        cout<<"4 . display "<<endl;
        cout<<"0 . exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch (choice){
            case 1:
                cout<<"Enter array size : ";
                cin>>n;

                for(int i = 0; i < n; i++)
                {
                    cout<<"Enter value : ";
                    cin>>value;
                    arr.push_back(value);
                }
                break;
            case 2:
                merge_sort(arr,0,arr.size() -1);
                cout<<"Array sorting using merge sort.";
                break;
            case 3:
                int result;
                cout << "Enter value to search (Binary): \n (do not enter unsorted array)";
                cin >> element;
                result = binarysearch(arr,element);
                if (result != -1) 
                {
                    cout << "Element at : "<<result<<endl;
                } 
                else 
                {
                    cout << "Element not found!" << endl;
                }
                break;
            case 4:
                display(arr,n);
                break;
            case 0:
                cout<<"Exiting.........!"<<endl;
                break;
            default:
                cout<<"Invalid choice."<<endl;
                break;
            }
    } while (choice != 0);
    
    return 0;

}