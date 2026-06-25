class RLEIterator {
public:
    deque<pair<int,int>>q;
    RLEIterator(vector<int>& encoding) {
        // populate freq, num to queue
        for(int i=0;i<encoding.size();i+=2){
            if(encoding[i] == 0)
                continue;
            q.push_back({encoding[i],encoding[i+1]});
        }
    }
    
    int next(int n) {

        while(q.size()){
            int freq = q.front().first, num = q.front().second;
            q.pop_front();

            if(n-freq>0){
                n-=freq; // more exhaustion needed 
            } else if(n-freq ==0){
                return num; // all consumed
            } else{
                q.push_front({freq-n,num}); // give remaining back to deque of current.
                return num;
            }
        }

        return -1;
        
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */