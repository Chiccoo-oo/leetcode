class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>f;
        for(char c :s){
            f[c]++;
        }
        vector<pair<char, int>>v(f.begin(),f.end());
        sort(v.begin(),v.end(),[] (auto &a , auto &b) {
            return a.second >b.second;
        });
        string a ="";
        for(auto &p :v){
            a+=string(p.second,p.first);
        }
        return a ;
        
    }
};