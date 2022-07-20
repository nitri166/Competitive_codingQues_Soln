#include <iostream>
#include <vector>
using namespace std;

// WE HAVE TO DIVIDE THE PAINTBOARDS IN SUCH A WAY THAT MINIMUM TIME IS
// REQUIRED TO PAINT ALL THE BOARDS

// WE HAVE TO FIND PARTITION VALUE IN THIS

// concept - search space minimization

// The function below checks if we hava a possible solution
// This means it checks if we have a mid point which can be used to do partition
bool isPossible(vector<int> arr, int k, int n, int mid)
{
    int sum = 0;
    int painter_count = 1;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] <= mid)
        {
            sum = sum + arr[i];
        }
        else
        {
            painter_count++;
            if (arr[i] > mid || painter_count > k)
            {
                return false;
            }

            // sum will be equated for which the above cond is false
            sum = arr[i];
        }
    }
    return true;
}
int painters_partition(vector<int> arr, int k, int n)
{
    int start = 0;
    // find the end of search space
    int sum = 0;
    for (int i = 0; i < n; i++)
    {

        sum += arr[i];
    }
    int end = sum;
    int mid = start + (end - start) / 2;
    // a variable which stores the answer
    int ans = -1;
    int i = 0;
    while (start <= end)
    {
        if (isPossible(arr, k, n, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{
    int n,k;
    cout<< "Enter the no of paintboards"<<endl;
    cin>>n;
    cout<<"Enter the no of painters"<<endl;
    cin>> k;
    int a; vector<int> arr;
    cout<<"Enter the size of each paint board"<<endl;
    for(int i=0;i<n;i++){
        cin >>a;
        arr.push_back(a);
    }

    cout<< "Division of the board will be done as follows"<<endl;
    cout<< painters_partition(arr,k,n);


    return 0;
}