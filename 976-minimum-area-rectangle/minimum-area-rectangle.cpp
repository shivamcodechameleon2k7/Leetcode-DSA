
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                // Rectangle needs different x and y coordinates
                if(x1 == x2 || y1 == y2) {
                    continue;
                }

                bool found1 = false;
                bool found2 = false;

                for(int k = 0; k < n; k++) {
                    if(points[k][0] == x1 &&
                       points[k][1] == y2) {
                        found1 = true;
                    }

                    if(points[k][0] == x2 &&
                       points[k][1] == y1) {
                        found2 = true;
                    }
                }

                if(found1 && found2) {
                    int area = abs(x2 - x1) * abs(y2 - y1);
                    ans = min(ans, area);
                }
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
