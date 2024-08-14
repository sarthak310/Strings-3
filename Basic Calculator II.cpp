//1. maintain tail like 282. - for each exp and num (curr), maintain calc and then tail
//2. using stack - doing / and * along with putting in stack, + and - after one traversal

//1.
//time: O(n)
//space: O(1)

class Solution {
public:
    int calculate(string s) {
        
        int calc = 0;
        int tail = 0;
        char exp = '+';
        for(int i = 0; i < s.length(); i++) {
            //cout<<curr<<" "<<calc<<" "<<tail<<" "<<exp<<endl;
            if(s[i] >= '0' && s[i] <= '9') {
                int curr = 0;
                while(i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    curr = curr*10 + (s[i] - '0');
                    i++;
                }
                i--;

                if(exp == '+') {
                    calc = calc+curr;
                    tail = +curr;
                }
                else if(exp == '-') {
                    calc = calc-curr;
                    tail = -curr;
                }
                else if(exp == '*') {
                    calc = calc-tail+tail*curr;
                    tail = tail*curr;
                }
                else if(exp == '/') {
                    calc = calc-tail+tail/curr;
                    tail = tail/curr;
                }
                //cout<<curr<<" "<<calc<<" "<<tail<<" "<<exp<<endl;
            }
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                exp = s[i];
            }
        }
        return calc;
    }
};


//2.
//time: O(2n) ~ O(n)
//space: O(n)
/*
class Solution {
public:
    int calculate(string s) {
        stack<int> order;
        char exp = '+';
        for(int i = 0; i < s.length(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                int curr = 0;
                while(i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    curr = curr*10 + (s[i] - '0');
                    i++;
                }
                i--;

                if(exp == '+') {
                    order.push(curr);
                }
                else if(exp == '-') {
                    order.push(-curr);
                }
                else if(exp == '*') {
                    int prev = order.top();
                    order.pop();
                    order.push(prev*curr);
                }
                else if(exp == '/') {
                    int prev = order.top();
                    order.pop();
                    order.push(prev/curr);
                }
            }
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                exp = s[i];
            }
        }
        int result = 0;
        while(!order.empty()) {
            result += order.top();
            order.pop();
        }
        return result;
    }
};
*/