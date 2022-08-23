class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        int maxarea=INT_MIN;
        for(int i=0;i<=n;i++){
            while(!st.empty()&&(i==n||heights[st.top()]>heights[i])){
                int ht=heights[st.top()];
                int width=0;
                st.pop();
                if(st.empty()){
                    width=i;
                }
                else{
                    width=i-st.top()-1;
                }
                maxarea=max(maxarea,ht*width);
            }
            st.push(i);
        }
        return maxarea;
    }
};