class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice=0,bob=0;
        for(int i = 1;i<colors.size();i++){
            if(colors[i]=='A' and colors[i-1]=='A' and colors[i+1]=='A')
                alice++;
            if(colors[i]=='B' and colors[i-1]=='B' and colors[i+1]=='B')
                bob++;
        }
        return alice>bob;
    }
};