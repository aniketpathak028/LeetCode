class Solution {
public:
    string findString(string s){
      stack<char> st;
      for(auto &ch: s) st.push(ch);
      int back_cnt= 0;
      string ans="";
      while(!st.empty()){
        char top= st.top();
        st.pop();
        if(top=='#') back_cnt++;
        else if(back_cnt) back_cnt--;
        else ans+= top;
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
  
    bool backspaceCompare(string s, string t) {
        if(findString(s)==findString(t)) return true;
        else return false;
    }
};