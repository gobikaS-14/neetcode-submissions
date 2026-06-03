//correct solution for any string
class Solution {
public:

    string encode(vector<string>& strs) {
        string encode;
        for(string s:strs){
            int len=s.size();
            encode.append(to_string(len));
            encode+='#';
            encode.append(s);
        }
        return encode;
    }

    vector<string> decode(string encode) {
        vector<string> decode;
        int i=0;
        int n=encode.size();
        while(i<n){
            int j=i;
            while(encode[j]!='#')   j++;
            int len=stoi(encode.substr(i,j-i));

            string temp="";
            int k=1;
            while(k<=len){
                j++;
                temp+=encode[j];
                k++;
            }
            decode.push_back(temp);
            i=j+1;
        }
        return decode;
    }
};
