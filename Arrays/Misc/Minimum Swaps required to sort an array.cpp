#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> arr, int n)
{
	vector<pair<int,int>>vec;
	for(int i=0;i<n;i++)
	    vec.push_back(make_pair(arr[i],i));
	sort(vec.begin(),vec.end());
	
	int swaps=0;
	for(int i=0;i<n;i++)
	{
	    while(vec[i].second != i)
	    {
	        swaps++;
	        swap(vec[i] , vec[vec[i].second]);
	    }
	}
	return swaps;
}


int main()
{

	vector<int> a = {5,4,6,2,1,3};
	int n = a.size();
	cout << minSwaps(a, n);
}