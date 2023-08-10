vector<int> get_matches(string s, string p) {
    vector<int> res;
    for (int i = s.find(p); i != string::npos; i = s.find(p, i + 1)) {
        res.push_back(i);
    }
    return res;
}