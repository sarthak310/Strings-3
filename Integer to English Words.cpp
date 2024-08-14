//time: O(logn)
//space: O(1)
//itertive
class Solution {
public:
    string numberToWords(int num) {
        // Handle the special case where the number is zero
        if (num == 0) return "Zero";

        // Arrays to store words for single digits, tens, and thousands
        const vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        const vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        const vector<string> thousands = {"", "Thousand", "Million", "Billion"};

        // StringBuilder to accumulate the result
        string result = "";
        int groupIndex = 0;

        // Process the number in chunks of 1000
        while (num > 0) {
            // Process the last three digits
            if (num % 1000 != 0) {
                string groupResult = "";
                int part = num % 1000;

                // Handle hundreds
                if (part >= 100) {
                    groupResult = ones[part / 100] + " Hundred ";
                    part %= 100;
                }

                // Handle tens and units
                if (part >= 20) {
                    groupResult += tens[part / 10] + " ";
                    part %= 10;
                }

                // Handle units
                if (part > 0) {
                    groupResult += ones[part] + " ";
                }

                // Append the scale (thousand, million, billion) for the current group
                groupResult += thousands[groupIndex] + " ";
                // Insert the group result at the beginning of the final result
                result = groupResult + result;
            }
            // Move to the next chunk of 1000
            num /= 1000;
            groupIndex++;
        }

        return result.substr(0, result.find_last_not_of(" ") + 1); // Remove trailing spaces
    }
};

//recursive
/*
class Solution {
public:
    // Arrays to store words for numbers less than 10, 20, and 100
    const vector<string> belowTen = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    const vector<string> belowTwenty = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    const vector<string> belowHundred = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

    // Main function to convert a number to English words
    string numberToWords(int num) {
        // Handle the special case where the number is zero
        if (num == 0) {
            return "Zero";
        }
        // Call the helper function to start the conversion
        return convertToWords(num);
    }

private:
    // Recursive function to convert numbers to words
    // Handles numbers based on their ranges: <10, <20, <100, <1000, <1000000, <1000000000, and >=1000000000
    string convertToWords(int num) {
        if (num < 10) {
            return belowTen[num];
        }
        if (num < 20) {
            return belowTwenty[num - 10];
        }
        if (num < 100) {
            return belowHundred[num / 10] + (num % 10 ? " " + convertToWords(num % 10) : "");
        }
        if (num < 1000) {
            return convertToWords(num / 100) + " Hundred" + (num % 100 ? " " + convertToWords(num % 100) : "");
        }
        if (num < 1000000) {
            return convertToWords(num / 1000) + " Thousand" + (num % 1000 ? " " + convertToWords(num % 1000) : "");
        }
        if (num < 1000000000) {
            return convertToWords(num / 1000000) + " Million" + (num % 1000000 ? " " + convertToWords(num % 1000000) : "");
        }
        return convertToWords(num / 1000000000) + " Billion" + (num % 1000000000 ? " " + convertToWords(num % 1000000000) : "");
    }
};
*/