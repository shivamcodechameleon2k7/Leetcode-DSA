// class Solution {
// public:
//     int romanToInt(string s) {
//         map<char,int> value = {
//             {'I',1}, {'V',5}, {'X',10}, {'L',50},
//             {'C',100}, {'D',500}, {'M',1000}
//             };
//             int result = 0;
//             for(int i = 0; i < s.size()-1;i++){
//                 if(value[s[i]] < value[s[i+1]]){
//                     result -= value[s[i]];
//                     }
//                 else {
//                     result += value[s[i]];
//                     }
//                 }
//             result += value[s.back()]; 
//             return result;
//         } 
// };

class Solution {
public:
    int val(char c) {
        if(c == 'I') return 1;
        if(c == 'V') return 5;
        if(c == 'X') return 10;
        if(c == 'L') return 50;
        if(c == 'C') return 100;
        if(c == 'D') return 500;
        return 1000;
    }

    int romanToInt(string s) {
        int result = 0;

        for(int i = 0; i < s.size() - 1; i++) {
            if(val(s[i]) < val(s[i + 1]))
                result -= val(s[i]);
            else
                result += val(s[i]);
        }

        result += val(s.back());

        return result;
    }
};