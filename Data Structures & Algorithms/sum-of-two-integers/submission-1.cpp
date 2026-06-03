//bruet force(using "+")
/*
class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int result = 0;
        int position = 0;

        while (a > 0 || b > 0 || carry > 0) {
            int bitA = a & 1;   // last bit of a
            int bitB = b & 1;   // last bit of b

            int total = bitA + bitB + carry;

            int resultBit = total % 2;  // current bit
            carry = total / 2;          // next carry

            result = result + (resultBit << position); // place bit

            a = a >> 1;  // move to next bit
            b = b >> 1;
            position++;
        }

        return result;
    }
};*/

class Solution {
public:
    int getSum(int a, int b) {
        int sum,carry;
        while(b!=0){
            sum=a^b;
            carry=(a&b)<<1;
            a=sum;
            b=carry;
        }
        return a;
    }
};        

