#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// EKO SPOJ PROBLEM

// concept - search space minimization

bool isPossible(int m, int n, vector<int> trees, int mid)
{
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (trees[i] > mid)
        {
            sum = sum+(trees[i] - mid);
        }
    }
    if (sum >= m)
    {
        return true;
    }
    return false;
}

long long int heightOfTree(vector<int> trees, int n, int m)
{
    sort(trees.begin(), trees.end());
    // we have to find the search space
    int s = 0;
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(trees[i], maxi);
    }
    long long int ans = -1;
    long long int e = maxi;
    long long int mid = s + (e - s) / 2;
    int i = 0;
    while (s <= e)
    {
        if (isPossible(m, n, trees, mid))
        {
            ans = mid;
            s = mid + 1;
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
    int n, m;
    cout << "Enter the no of trees" <<endl;
    cin >> n;
    cout << "Enter the amount of wood required" << endl;
    cin >> m;
    int a;
    vector<int> trees;
    
    cout << "Enter the height of each tree" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        trees.push_back(a);
    }

    cout << "Maximum integer height of the sawblade that still allows him to cut off at least m metres of wood will be" << endl;
    cout << heightOfTree(trees, n, m);
    return 0;
}