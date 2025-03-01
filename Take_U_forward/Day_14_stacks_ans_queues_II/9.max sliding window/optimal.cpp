#include <bits/stdc++.h> 

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> ans(n, INT_MIN);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && a[st.top()] > a[i]){
            int next_smaller_right = i;
            int index = st.top();
            st.pop();
            int next_smaller_left;
            if(st.empty())
                next_smaller_left = -1;
            else
                next_smaller_left = st.top();
            int range = next_smaller_right - next_smaller_left - 1;
            ans[range-1] = max(ans[range - 1], a[index]);
        }
        st.push(i);
    }


    //for remaining elements of stack the next smaller right is n, because there is no smaller element in the array that that one
    while(!st.empty()){
        int index = st.top();
        int next_smaller_right = n;
        st.pop();

        int next_smaller_left;
        if(st.empty())
            next_smaller_left = -1;
        else
            next_smaller_left = st.top();
        int range = next_smaller_right - next_smaller_left -1;
        ans[range - 1] = max(ans[range - 1], a[index]);
    }
    // Some values in ans[] may be INT_MIN, so we propagate the maximum values forward to ensure all window sizes are correctly filled.
    for(int i = n-2; i >= 0; i--){
        ans[i] = max(ans[i], ans[i+1]);
    }
    return ans;
}