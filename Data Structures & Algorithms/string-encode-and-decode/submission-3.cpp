/*Works only if strings do not contain #.
In your failing test case:
"!@#$%^&*()"
The string itself contains #.
So when decoding, the split happens at the wrong #, producing:
"!@","$%^&*()"  ❌
*/
 /*class Solution {
public:

    string encode(vector<string>& strs) {
        string e;
        for(string s :strs){
            e.append(s); 
            e.append("#"); 
        }
        return e;
         }

    vector<string> decode(string e) {
        vector<string> d;
        string temp;
        for (char ch : e){
            if(ch!='#'){
                temp+=ch;
            }
            else{
                d.push_back(temp);
                temp="";
            }
        }
        return d;
    }
};
*/

class Solution {
public:

    string encode(vector<string>& strs) {
        string e;
        for(string s : strs){
            int len = s.size();
            e.append(to_string(len) + "#");
            e.append(s);
        }
        return e;
    }

   vector<string> decode(string e) {
    vector<string> d;
    int i = 0;

    while (i < e.size()) {
        int j=i;
        while(e[j]!='#')j++;
        int len = stoi(e.substr(i,j-i));
        string temp = "";
        int k = 1;
        while (k <= len) {
            j++;
            temp += e[j]; // push character as string
            k++;
        }

        d.push_back(temp);

        i = j+1;     // move i to next length
        j = i + 1; // same as your original plan
    }

    return d;
}

};
