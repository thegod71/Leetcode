class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>days={31,28,31,30,31,30,31,31,30,31,30,31};
        vector<int>prefix(13,0);
        for(int i=0;i<12;i++){
            prefix[i+1]=prefix[i]+days[i];
        }
        auto today=[&](string s){
            int d=stoi(s.substr(3,2));
            int month=stoi(s.substr(0,2));
            return prefix[month-1]+d;
        };
        int start=max(today(arriveAlice),today(arriveBob));
        int end=min(today(leaveAlice),today(leaveBob));
        return max(0,end-start+1);
    }
};