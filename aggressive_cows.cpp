#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//concept - serach space minimization
// Place the aggressive cows in those position such that the minimum distance between
// any two of them is as large as possible


bool isPossible(vector<int> stalls, int k, int n, int mid)
{
    int cow_count = 1;
    int lastPos = stalls[0];
    // let a be the position where we place first cow
    // a = last pos = 0
    // let b be the postion where we want to place the second cow
    for (int i = 0; i < n; i++)
    {
        if (stalls[i] - lastPos >= mid)
        {
            cow_count++;
            if (cow_count == k)
            {
                return true;
            } // placing the next cow at the postion for which cond was true
            lastPos = stalls[i];
        }
    }

    return false;
}

int aggressiveCows(vector<int> stalls, int k, int n)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, stalls[i]);
    }
    int ans = -1;
    int e = maxi;
    int mid = s + (e - s) / 2;
    int i = 0;
    while (s <= e)
    {
        if (isPossible(stalls, k, n, mid))
        {
            ans = mid;
            s = mid + 1; // as we want largest solution
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main()
{
    int n, k;
    cout << "Enter the no of stalls" << endl;
    cin >> n;
    cout << "Enter the no of cows" << endl;
    cin >> k;
    int a;
    vector<int> stalls;
    cout << "Enter the position of each stall" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        stalls.push_back(a);
    }

    cout << "The maximum distance for which cows will not get aggressive will be" << endl;
    cout << aggressiveCows(stalls, k, n);

    return 0;
}