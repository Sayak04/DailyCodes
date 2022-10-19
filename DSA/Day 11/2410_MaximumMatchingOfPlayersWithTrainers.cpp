class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int inPlay = players.size() - 1, inTrain = trainers.size() - 1;
        
        int ans = 0;
        while(inPlay >= 0 && inTrain >= 0) {
            if(players[inPlay] <= trainers[inTrain]) {
                ans++;
                inPlay--;
                inTrain--;
            }
            else if(players[inPlay] > trainers[inTrain]) inPlay--;
        }
        return ans;
    }
};