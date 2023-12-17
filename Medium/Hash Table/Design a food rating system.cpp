class FoodRatings {
    private:
    unordered_map<string, pair<string, int>> foodData;  // food -> (cuisine, rating)
    unordered_map<string, pair<int, string>> cuisineRatings;  // cuisine -> (rating, food)

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            // Initialize foodData
            foodData[food] = make_pair(cuisine, rating);

            // Update cuisineRatings
            if (cuisineRatings.find(cuisine) == cuisineRatings.end() || rating > cuisineRatings[cuisine].first ||
                (rating == cuisineRatings[cuisine].first && food < cuisineRatings[cuisine].second)) {
                cuisineRatings[cuisine] = make_pair(rating, food);
            }
        }
        
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodData[food].first;
    int oldRating = foodData[food].second;

    // Update foodData
    foodData[food].second = newRating;

    // Update cuisineRatings
    if (newRating > cuisineRatings[cuisine].first ||
        (newRating == cuisineRatings[cuisine].first && food < cuisineRatings[cuisine].second)) {
        cuisineRatings[cuisine] = make_pair(newRating, food);
    } else if (oldRating == cuisineRatings[cuisine].first && food == cuisineRatings[cuisine].second) {
        // If the updated food was the highest rated, update the cuisineRatings directly
        cuisineRatings[cuisine] = make_pair(newRating, food);
    }
    }
    
    string highestRated(string cuisine) {
         return cuisineRatings[cuisine].second;
        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
