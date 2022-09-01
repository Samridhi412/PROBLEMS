class MedianFinder {
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
public:
    MedianFinder() {
        while(!maxheap.empty()){
            maxheap.pop();
        }
        while(!minheap.empty()){
            minheap.pop();
        }
    }
    
    void addNum(int num) {
        if(maxheap.empty()){
            maxheap.push(num);
        }
        else if(maxheap.size()>minheap.size()){
            if(maxheap.top()>num){
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(num);
            }
            else{
                minheap.push(num);
            }
        }
        else{
            if(minheap.top()<num){
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(num);
            }
            else{
                maxheap.push(num);
            }
        }
    }
    
    double findMedian() {
        double ans=0.0;
        if(minheap.size()==maxheap.size()){
            return (minheap.top()+maxheap.top())/2.0;
        }
        return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */