

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {

                        long long x[4] = {
                            points[i][0], points[j][0],
                            points[k][0], points[l][0]
                        };

                        long long y[4] = {
                            points[i][1], points[j][1],
                            points[k][1], points[l][1]
                        };

                        int pairs[3][4] = {
                            {0, 1, 2, 3},
                            {0, 2, 1, 3},
                            {0, 3, 1, 2}
                        };

                        for (int p = 0; p < 3; p++) {
                            int a = pairs[p][0];
                            int b = pairs[p][1];
                            int c = pairs[p][2];
                            int d = pairs[p][3];

                            // Same midpoint
                            if (x[a] + x[b] != x[c] + x[d] ||
                                y[a] + y[b] != y[c] + y[d]) {
                                continue;
                            }

                            // Equal diagonal lengths
                            long long dx = x[a] - x[b];
                            long long dy = y[a] - y[b];
                            long long diag1 = dx * dx + dy * dy;

                            dx = x[c] - x[d];
                            dy = y[c] - y[d];
                            long long diag2 = dx * dx + dy * dy;

                            if (diag1 != diag2) {
                                continue;
                            }

                            // Area using two adjacent sides
                            long long ax = x[b] - x[a];
                            long long ay = y[b] - y[a];
                            long long bx = x[c] - x[a];
                            long long by = y[c] - y[a];

                            double area =
                                abs(ax * by - ay * bx);

                            if (area > 0 &&
                                (ans == 0 || area < ans)) {
                                ans = area;
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};
