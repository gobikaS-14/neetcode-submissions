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
        int i = 0, j = 1;

        while (i < e.size()) {

            // ✅ FIX 1 — convert length correctly using stoi()
            int hashPos = i;
            while (e[hashPos] != '#') hashPos++;

            int len = stoi(e.substr(i, hashPos - i));  // <-- ONLY THIS CHANGED

            // j moves to first character after '#'
            j = hashPos + 1;

            // Read 'len' characters (your original k-loop)
            string temp = "";
            int k = 1;
            while (k <= len) {
                temp += e[j]; 
                j++;
                k++;
            }

            d.push_back(temp);

            // Move i and j (your original logic)
            i = j;
            j = i + 1;
        }

        return d;
    }
};
