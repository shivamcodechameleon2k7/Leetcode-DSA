
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        // Count servers in each row and column
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int count = 0;

        // Count communicating servers
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 &&
                   (row[i] > 1 || col[j] > 1)) {
                    count++;
                }
            }
        }

        return count;
    }
};

/*Get dimensions: m = grid.size() gives rows and n = grid[0].size() gives columns.
Create two arrays: row(m, 0) stores the number of servers in each row, and col(n, 0) stores the number of servers in each column.
Count servers: Traverse the grid using nested loops. If grid[i][j] == 1, increment row[i] and col[j].
Initialize counter: int count = 0 to store communicating servers.
Check communication: Traverse the grid again. If grid[i][j] == 1 and (row[i] > 1 || col[j] > 1), increment count.
Understand the condition:
- grid[i][j] == 1 → Server exists.
- row[i] > 1 → Another server exists in the same row.
- col[j] > 1 → Another server exists in the same column.
- || → Either condition is sufficient.
Return: return count.*/
