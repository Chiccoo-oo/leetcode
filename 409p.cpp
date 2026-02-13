class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char , int>mp ; 
        for(char c :s ){
            mp[c]++;
        }
        int l = 0 ; 
        bool odd = false ; 
        for(auto it :mp){
            l +=(it.second/2)*2 ; 
            if(it.second %2 ==1 ){
                odd = true ; 
            }
        }
        if(odd) l+=1;
        return l ;
    }
};