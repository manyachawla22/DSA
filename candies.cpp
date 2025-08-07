class Solution {
public:
    vector<int> candies;
    int count;
    void check(int index, const vector<int> &ratings){
        if(index-1>=0){
            if(ratings[index-1] < ratings[index]){
                if(candies[index-1] >= candies[index]){
                    candies[index] += 1;
                    ++count;
                    check(index,ratings); // do recursion on check!
                }
            } 
        }
    }
    int candy(vector<int>& ratings) {
        for(int i = 0; i<ratings.size(); ++i){
            candies.push_back(1);
            ++count;
        }
        for(int i = 0; i<ratings.size(); ++i)
            check(i, ratings);
        return count;
    }
};
