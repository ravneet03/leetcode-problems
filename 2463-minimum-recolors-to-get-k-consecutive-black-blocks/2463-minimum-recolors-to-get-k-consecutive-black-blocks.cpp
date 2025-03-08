class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int j=0+k;
        int ans=k;
        for (int i=0; j<=blocks.length();i++){
            int countr=0;
            for(int a=i;a<j;a++){
                if(blocks[a]=='W') countr++;
            }
            ans=min(ans,countr);
            j++;
        }
        return ans;
    }
};