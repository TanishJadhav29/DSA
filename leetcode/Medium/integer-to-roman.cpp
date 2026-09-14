// Problem: Integer to Roman
// Platform: leetcode
// Rating/Difficulty: Medium
// Language: cpp
// Verdict: Accepted
// URL: https://leetcode.com/problems/integer-to-roman/
// Solved on: 2026-09-14T19:38:39.160Z

class Solution {
public:
    string intToRoman(int num) {
        //3749-> 
        //58-> LVIII
        //1994->MCMXCIV
        map<int, string> m;
            m[1] = "I";
            m[2] = "II";
            m[3] = "III";
            m[4] = "IV";
            m[5] = "V";
            m[6] = "VI";
            m[7] = "VII";
            m[8] = "VIII";
            m[9] = "IX";

            m[10] = "X";
            m[20] = "XX";
            m[30] = "XXX";
            m[40] = "XL";
            m[50] = "L";
            m[60] = "LX";
            m[70] = "LXX";
            m[80] = "LXXX";
            m[90] = "XC";

            m[100] = "C";
            m[200] = "CC";
            m[300] = "CCC";
            m[400] = "CD";
            m[500] = "D";
            m[600] = "DC";
            m[700] = "DCC";
            m[800] = "DCCC";
            m[900] = "CM";

            m[1000] = "M";
            m[2000] = "MM";
            m[3000] = "MMM";
        
            string len = to_string(num);
            int length = len.size()-1;
            string ans="";
            while(length>=0){
                if(length==0){
                    ans+=m[num];break;
                }
                int number = pow(10,length);
                int k = (num/number)*number;
                ans+=m[k];
                cout<<length<<" "<<num<< " "<<number<<" "<<k<<" "<<m[k]<<endl;
                num=num-k;
                length--;
            }
        return ans;
    }
};