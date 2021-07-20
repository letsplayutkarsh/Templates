vector<int> prefix_function(string &s) {
    int n = (int)s.length();
    vector<int> lcs(n);
    for (int i = 1; i < n; i++) {
        int j = lcs[i-1];
        while (j > 0 && s[i] != s[j])
            j = lcs[j-1];
        if (s[i] == s[j])
            j++;
        lcs[i] = j;
    }
    return lcs;
}
