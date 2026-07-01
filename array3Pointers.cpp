int minimizeAbsDifference(vector<int>& A, vector<int>& B, vector<int>& C) {
    int n = A.size(), m = B.size(), p = C.size();
    int i = 0, j = 0, k = 0;
    int answer = INT_MAX;

    while(i < n && j < m && k < p) {
        // Calculate current max difference
        int diff = max({abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])});
        answer = min(answer, diff);

        // Find the minimum value among current elements
        int minVal = min({A[i], B[j], C[k]});
        
        // Advance the pointer with minimum value
        if(minVal == A[i]) i++;
        else if(minVal == B[j]) j++;
        else k++;
    }

    return answer;
}
