class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<int> inDegree(numCourses, 0);
            map<int, vector<int>> mp;
    
            for(auto x: prerequisites){
                inDegree[x[0]]++;
                mp[x[1]].push_back(x[0]);
            }
    
            queue<int> q;
            for(int i = 0; i < numCourses; i++){
                if(inDegree[i] == 0) q.push(i);
            }
            int topo = 0;
            while(!q.empty()){
                int front = q.front();
                q.pop();
    
                topo++; //node visited
                for(auto i: mp[front]){
                    inDegree[i]--;
                    if(inDegree[i] ==0) q.push(i);
                }
            }
            return topo == numCourses; //return all nodes visited or not
        }
    };