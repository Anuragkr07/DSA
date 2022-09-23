// Problem Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minEle=prices[0];
        int profit=INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<minEle)
                minEle=prices[i];
            else if(prices[i]-minEle > profit)
                profit=prices[i]-minEle;
        }
        return profit;
    }
};