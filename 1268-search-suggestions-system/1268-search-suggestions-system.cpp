class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(), products.end()); 
        string toSearch= "";
        for(auto ch: searchWord){
          vector<string> suggestions;
          toSearch+= ch;
          auto it= lower_bound(products.begin(), products.end(), toSearch);
          for(int pos= 0; pos<3 && it+pos!=products.end(); ++pos){
            string foundWord= products[(it-products.begin())+pos];
            if(foundWord.find(toSearch)) break;
            suggestions.push_back(foundWord);
          }
          ans.push_back(suggestions);
        }
        return ans;
    }
};