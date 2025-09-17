//C++

class FoodRatings {
    unordered_map<string, string> food_cuisine;
    unordered_map<string, int> food_rate;
    unordered_map<string, set<pair<int,string>>> cuisine_rate;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0; i<n; i++){
            string f = foods[i];
            string c = cuisines[i];
            int r = ratings[i];
            food_cuisine[f] = c;
            food_rate[f] = r;
            cuisine_rate[c].insert({r, f});
        }
    }
    
    void changeRating(string food, int newRating) {
        int x = food_rate[food];
        string c = food_cuisine[food];
        cuisine_rate[c].erase({x, food});
        food_rate[food] = newRating;
        cuisine_rate[c].insert({newRating, food});
    }
    
    string highestRated(string cuisine) {
        set<pair<int,string>> &st = cuisine_rate[cuisine];
        int mxi = (*(prev(st.end()))).first;
        auto it = st.lower_bound({mxi, ""});;
        if(it == st.end()){
            return "-1";
        }
        return it->second;
    }
};
