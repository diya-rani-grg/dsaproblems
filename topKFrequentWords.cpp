vector<string> topKFrequent(vector<string>& words, int k) {
    
        unordered_map<string, int> mp;

        // Count frequency
        for (string &word : words) {
            mp[word]++;
        }

        // Store as {word, frequency}
        vector<pair<string, int>> vec;

        for (auto &it : mp) {
            vec.push_back({it.first, it.second});
        }

        // Custom sorting
        sort(vec.begin(), vec.end(), [](pair<string,int> &a, pair<string,int> &b) {
            if (a.second == b.second)
                return a.first < b.first;   // lexicographical order
            return a.second > b.second;     // higher frequency first
        });

        vector<string> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(vec[i].first);
        }

        return ans;
}