//brute force -time limit exceeded-o(n^3) in worst case
//run in onlien compiler
/*
class Solution {
public:
    bool isValid(string s) {
        
        string old=s;
        while(true){
            
            while(s.find("()") !=-1){
                s.erase(s.find("()"),2);
            }

             while(s.find("{}") !=-1){
                s.erase(s.find("{}"),2);
            }
             while(s.find("[]") !=-1){
                s.erase(s.find("[]"),2);
            }
            
            if(s==old) break;
        }
        if(s.empty()) return true;
        return false;
    }
};*/

//optimal
class Solution {
public:
    bool isValid(string s) {
          // stack to store opening brackets
          stack<char> st;

          for(char ch:s){

            if(ch=='('|| ch=='{'|| ch=='[') st.push(ch);

            else
            {//closing brackets

            if(st.empty()) return false;

            if((ch == ')' && st.top() != '(') ||
                (ch == '}' && st.top() != '{') ||
                (ch == ']' && st.top() != '[')) return false;//no match found
            
            st.pop();//match found-remove

            }
          }
          return st.empty();
    }
};
