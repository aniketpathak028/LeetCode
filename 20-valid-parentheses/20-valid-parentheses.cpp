class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch: s){
          if(ch==']' || ch==')' || ch=='}'){
              if(st.empty()) return false;
              if(ch==']'){
                if(st.top()=='[') st.pop();
                else return false;
              }
              if(ch=='}'){
                if(st.top()=='{') st.pop();
                else return false;
              }
              if(ch==')'){
                if(st.top()=='(') st.pop();
                else return false;
              }
          }
          else st.push(ch);
        }
      return st.empty();
    }
};