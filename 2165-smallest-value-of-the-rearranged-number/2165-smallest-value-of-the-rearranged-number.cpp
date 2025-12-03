class Solution {
public:
    long long smallestNumber(long long num) {
        string s=to_string(num);
        
        if(num>0){
            sort(s.begin(),s.end());
            if(s[0]=='0'){
                int i=0;
                while(s[i]=='0'){
                    i++;
                }
                swap(s[0],s[i]);
            }
        }
        else{
            sort(s.begin()+1,s.end(),greater<char>());
            if(s[1]=='0'){
                for(char c=1;c<s.size();c++){
                    if(s[c]!=0) swap(s[1],s[c]);
                    break;
                }
            }
        }
        return stoll(s);
    
    }
};