/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        int place = 3;
        while(int(num / pow(10, place)) == 0){
            place--;
        }
        string romanEquivalent;
        vector<char> oneEq{'I','X','C','M'}, fiveEq{'V','L','D'};
        char currentEq, currFiveEq, currGreaterEq;
        while(num > 0){
            int currentFaceValue = num/pow(10,place);
            currentEq = oneEq[place];
            if(place < 3){
                // num < 4000 as given in constraints, hence it is not required
                currFiveEq = fiveEq[place];
                currGreaterEq = oneEq[place+1];
            }
            if(currentFaceValue == 9){
                // Typecasting the char to string and XC, IX etc.
                romanEquivalent += string(1,currentEq) + currGreaterEq;
            }else if(currentFaceValue < 9 and currentFaceValue >= 5){
                // Add fiveEquivalent and subsequent characters if necessary
                romanEquivalent += currFiveEq;
                currentFaceValue -= 5;
                if(currentFaceValue)
                    romanEquivalent += string(currentFaceValue, currentEq);
            }else if(currentFaceValue == 4){
                romanEquivalent += string(1,currentEq) + currFiveEq;
            }else{
                // Add number of characters required
                romanEquivalent += string(currentFaceValue, currentEq);
            }
            int powerOfTen = pow(10,place);
            num %= powerOfTen;
            place--;
        }
        return romanEquivalent;
    }
};
// @lc code=end