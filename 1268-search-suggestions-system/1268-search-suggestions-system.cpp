class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans; // answer vector
        sort(products.begin(), products.end()); // sort products array
        string toSearch= ""; // string to be searched at every character
        for(auto ch: searchWord){ // iterate through the search word
          vector<string> suggestions; // suggestions vector
          toSearch+= ch; 
          auto it= lower_bound(products.begin(), products.end(), toSearch); // finding the 1st matching word in the products vector
          for(int pos= 0; pos<3 && it+pos!=products.end(); ++pos){ // iterate for 3 words from the 1st word
            string foundWord= products[(it-products.begin())+pos]; 
            if(foundWord.find(toSearch)) break; // if the matched substring is not a prefix break
            suggestions.push_back(foundWord); // else add the word into suggestions
          }
          ans.push_back(suggestions); // add the suggestions into ans
        }
        return ans;
    }
};