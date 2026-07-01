vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size();
    stack<int> s;
    
    for(int i = 0; i < n; i++) {
        // Current asteroid survives until proven otherwise
        bool destroyed = false;
        
        while(!s.empty() && s.top() > 0 && asteroids[i] < 0) {
            // Collision: right-moving (top) vs left-moving (current)
            if(abs(s.top()) < abs(asteroids[i])) {
                s.pop(); // stack asteroid explodes
            }
            else if(abs(s.top()) == abs(asteroids[i])) {
                s.pop(); // both explode
                destroyed = true;
                break;
            }
            else {
                destroyed = true; // current asteroid explodes
                break;
            }
        }
        
        if(!destroyed) {
            s.push(asteroids[i]);
        }
    }
    
    vector<int> ans;
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}
