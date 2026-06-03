class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for(string token:tokens){
            if(token == "+" || token == "-" || 
                token == "*" || token == "/"){
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                int result;
                if (token == "+")
                    result = b + a;
                else if (token == "-")
                    result = b - a;
                else if (token == "*")
                    result = b * a;
                else
                    result = b / a; // truncates toward zero
                s.push(result);
                }
            else{
                    s.push(stoi(token));
                }
        }
         return s.top();
        }
       

    };