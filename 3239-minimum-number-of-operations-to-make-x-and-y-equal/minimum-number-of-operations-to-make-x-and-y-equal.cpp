class Solution {
public:
    int minimumOperationsToMakeEqual(int a, int y) {
        // mininum steps again bfs apprach 
        //each num will act as a node 
        queue<pair<int,int>> q;
        q.push({a,0});
        // for visited make use of set 
        unordered_set <int> st;
        st.insert(a);
        while(!q.empty()){
            auto out = q.front();
            q.pop();
            int node = out.first;
            int x = node;
            int step = out.second;
            if(node == y){
                return step;
            }
            int nextNode ;
            if(x%11 == 0 && st.find(x/11)==st.end()){
                q.push({x/11,step+1});
                st.insert(x/11);
            }
            if(x%5 == 0 && st.find(x/5)==st.end()){
                q.push({x/5,step+1});
                st.insert(x/5);
            }
            if(st.find(x+1)==st.end()){
            q.push({x+1,step+1});
            st.insert(x+1);
            }
            if(st.find(x-1)==st.end()){
            q.push({x-1,step+1});
            st.insert(x-1);
            }
        }
        return -1;


    }
};