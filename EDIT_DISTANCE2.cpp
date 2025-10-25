#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int editdistres(string& s1, string& s2, int m, int n, vector<vector<int>>& memo) {
    // Base cases
    if (m == 0) return n;
    if (n == 0) return m;
    
    // Check memo
    if (memo[m][n] != -1) {
        return memo[m][n];
    }
    
    // Characters match
    if (s1[m-1] == s2[n-1]) {
        return memo[m][n] = editdistres(s1, s2, m-1, n-1, memo);
    }
    
    // Characters don't match - try all three operations
    return memo[m][n] = 1 + min({editdistres(s1, s2, m, n-1, memo),    // Insert
                                editdistres(s1, s2, m-1, n, memo),     // Delete
                                editdistres(s1, s2, m-1, n-1, memo)}); // Replace
}

int editdist(string& s1, string& s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
    return editdistres(s1, s2, m, n, memo);
}

int main() {
    string s1 = "abcd";
    string s2 = "bcfe";
    cout << editdist(s1, s2) << endl;  // Output: 3
    return 0;
}