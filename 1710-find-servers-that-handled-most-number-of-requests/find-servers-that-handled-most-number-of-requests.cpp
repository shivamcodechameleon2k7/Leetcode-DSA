class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;

        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            int currTime = arrival[i];

            // Release servers whose tasks are completed
            while (!busy.empty() && busy.top().first <= currTime) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // If no server is available, drop the request
            if (available.empty()) {
                continue;
            }

            // Find the first available server >= i % k
            auto it = available.lower_bound(i % k);

            // Wrap around if no server is found
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Assign request to server
            available.erase(it);

            count[server]++;

            // Mark server as busy
            busy.push({currTime + load[i], server});
        }

        // Find maximum number of requests handled
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};