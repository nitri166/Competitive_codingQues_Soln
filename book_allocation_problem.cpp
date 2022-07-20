#include<iostream>
#include<vector>
using namespace std;
// concept - search space minimization
bool isPossible(vector<int> arr, int n , int m , int mid){
    int stuCount=1; 
    int pageSum =0;// page alloted for first student
    for(int i =0;i<n;i++){
        if(pageSum+arr[i]<=mid){
                pageSum+=arr[i];
        }
        else{ // when the page sum is greater than mid then go to next student
            stuCount++;
            if(stuCount>m || arr[i]>mid){
                return false;

            }
            // at the end of loop substitute the page sum for next student
            pageSum = arr[i]; // this is the next element of array having pages

        }
    }
    return true;
    
}



int allocateBooks(vector<int> arr, int n , int m){

    int s=0;
    int sum =0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int e = sum;
    int ans = -1;

    int mid = s+(e-s)/2;

    int i =0;
    while(s<=e){
        if(isPossible(arr,n,m,mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;}
        mid= s+(e-s)/2;    
    }
    return ans;


}


int main(){
    int n,m;
    cout<<"Enter the no of books"<<endl;
    cin>>n;
    cout<<"Enter the no of students"<<endl;
    cin>>m;
    int a;
    vector<int> arr;
    cout<< "Enter the no of pages in the book"<<endl;
    for(int i =0;i<n;i++){
        cin>>a;
        arr.push_back(a);


    }

    cout<<"No of pages allocated to each student would be"<<endl;
    cout<<allocateBooks(arr,n,m);
    
    
    return 0;
}