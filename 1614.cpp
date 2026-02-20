class Solution {
public:
    int maxDepth(string s) {
        int d =  0 ; 
        int md = 0 ; 
        for(char c :s ){
            if(c=='('){
                d++; 
                md =max(d ,md);
            }
            else if(c==')'){
                d--;
            }
        }
        return md ; 
        
    }
};