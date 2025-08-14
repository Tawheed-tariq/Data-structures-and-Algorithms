class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b)
        {
            return a[1] < b[1]; 
        });
        int count =1;
        pair<int, int> temp;
        temp.first = points[0][0];
        temp.second = points[0][1];

        for(int i = 1; i < points.size(); i++){
            vector<int> point = points[i];
            if(point[0] <= temp.second){
                temp.second = min(temp.second, point[1]);
                temp.first = max(temp.first, point[0]);
            }else{
                count++;
                temp.first = point[0];
                temp.second = point[1];
            }
        }

        return count;
    }
};