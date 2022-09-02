typedef pair<int,int> pii;
class SGTree{
    vector<int> seg;
    public:
    SGTree(int n){
        seg.resize(4*n);
    }
    int getsum(int ind,int low,int high,int l,int r){
        //no overlap
        if(high<l||r<low)return 0;
        // complete overlap
        else if(l<=low&&high<=r){
            return seg[ind];
        }
        int mid=(low+high)>>1;
        int left=getsum(2*ind+1,low,mid,l,r);
        int right=getsum(2*ind+2,mid+1,high,l,r);
        return left+right;
    }
    void update(int ind,int low,int high,int index){
        if(low==high){
            seg[ind]=1;
            return;
        }
        int mid=(low+high)>>1;
        if(index<=mid)update(2*ind+1,low,mid,index);
        else update(2*ind+2,mid+1,high,index);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
};
/*********another approach but only for postiive elements*********/
// class SGTree{
//     vector<int> seg;
//     public:
//     SGTree(int n){
//         seg.resize(4*n+4);
//     }
//     void build(int ind,int low,int high,int freq[]){
//         if(low==high){
//             seg[ind]=freq[low];
//             return;
//         }
//         int mid=(low+high)>>1;
//         build(2*ind+1,low,mid,freq);
//         build(2*ind+2,mid+1,high,freq);
//         seg[ind]=seg[2*ind+1]+seg[2*ind+2];
//     }
//     void update(int ind,int low,int high,int index){
//         if(low==high){
//             seg[ind]-=1;
//             return;
//         }
//         int mid=(low+high)>>1;
//         if(index<=mid)update(2*ind+1,low,mid,index);
//         else update(2*ind+2,mid+1,high,index);
//         seg[ind]=seg[2*ind+1]+seg[2*ind+2];
//     }
//     int query(int ind,int low,int high,int l,int r){
//         //no overlap
//         if(high<l||r<low)return 0;
//         //complete overlap
//         else if(l<=low&&high<=r){
//             return seg[ind];
//         }
//         //partial overlap
//         int mid=(low+high)>>1;
//         int left=query(2*ind+1,low,mid,l,r);
//         int right=query(2*ind+2,mid+1,high,l,r);
//         return left+right;
//     }
// };

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        SGTree st(n);
        while(!pq.empty()){
            int nodeindex=pq.top().second;
            int node=pq.top().first;
            pq.pop();
            res[nodeindex]=st.getsum(0,0,n-1,nodeindex+1,n-1);
            st.update(0,0,n-1,nodeindex);
        }
        // int maxi=*max_element(nums.begin(),nums.end());
        // int freq[maxi+1];
        // memset(freq,0,sizeof(freq));
        // for(int i=0;i<n;i++){
        //     freq[nums[i]]++;
        // }
        // SGTree st(maxi+1);
        // st.build(0,0,maxi,freq);
        // vector<int> res;
        // for(int i=0;i<n;i++){
        //     freq[nums[i]]--;
        //     st.update(0,0,maxi,nums[i]);
        //     res.push_back(st.query(0,0,maxi,1,nums[i]-1));
        // }
        // return res;
        
        // INVERSION COUNT
       
        // mergesort(nums,0,n-1,res);
        return res;
    }
    
};