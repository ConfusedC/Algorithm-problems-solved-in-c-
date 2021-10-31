/*Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

 

Example 1:
Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Example 2:
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;
        int res = 0;
        for(int i = 0; i < n; i++){
            unordered_map<string, int> m;
            int dup = 0;
            int max_count = 0;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1]){
                    dup++;
                    continue;
                }
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                int gcd = __gcd(x, y);
                x /= gcd;
                y /= gcd;
                string s = to_string(x) + "," + to_string(y);
                m[s]++;
                max_count = max(max_count, m[s]);
            }
            res = max(res, max_count + dup + 1);
        }
        return res;
    }
};