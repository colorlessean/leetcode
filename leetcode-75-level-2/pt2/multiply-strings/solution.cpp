// #define VERBOSE

class Solution {
public:
    /*
    int string_to_int(string str) {
        int val = 0;
        for (int i = 0; i < str.size(); i++) {
            val += pow(10, i) * (str[str.size() - 1 - i] - '0');
        }
        
        #ifdef VERBOSE
        cout << val << endl;
        #endif
        
        return val;
    }
    
    string int_to_string(int num) {
        string val = "";

        val.insert(0, 1, (char)(num%10 + '0'));
        while (num / 10 > 0) {
            num /= 10;
            val.insert(0, 1, (char)(num%10 + '0'));
        }
        
        #ifdef VERBOSE
        cout << val << endl;
        #endif
        
        return val;
    }
    */
    
    string multiply(string num1, string num2) {        
        /*
        // could just convert both into integers and then just go back
        int first = string_to_int(num1);
        int second = string_to_int(num2);
        
        signed long long int product = first * second;
        
        string result = int_to_string(product);
        
        return result;
        */
        
        #ifdef VERBOSE
        for (int i = 0; i < num1.size(); i++) {
            int digit1 = num1[i] - '0';
            cout << "num1: " << digit1 << " num2: ";
            for (int j = 0; j < num2.size(); j++) {
                int digit2 = num2[j] - '0';
                cout << digit2 << " ";
            }
            cout << endl;
        }
        #endif
        
        // break each num1 digit into its place value pair and then go nuts
        vector<string> multiplied;
        
        // do the multiplication of each digit and push intermediate products to the multiplied list
        string intermediate_builder = "";
        for (int i = num1.size()-1; i >= 0; i--) {
            string intermediate = intermediate_builder;
            intermediate_builder.push_back('0');
            int carry = 0;
            
            int digit1 = num1[i] - '0';
            for (int j = num2.size()-1; j >= 0; j--) {
                int digit2 = num2[j] - '0';
                int product = (digit1*digit2) + carry;
                int digit = product % 10;
                
                intermediate.insert(0, 1, (char)(digit + '0'));
                
                carry = product / 10;
            }
            
            if (carry != 0) {
                intermediate.insert(0, 1, (char)(carry + '0'));
            }
            
            multiplied.push_back(intermediate);
        }
        
        // pad each of the numbers in the set without the proper number of digits i.e. add leading 0s
        int max_size = multiplied[multiplied.size()-1].size();
        for (int i = 0; i < multiplied.size(); i++) {
            int diff = max_size - multiplied[i].size();
            multiplied[i].insert(0, diff, '0');
        }
        
        #ifdef VERBOSE
        for (int i = 0; i < multiplied.size(); i++) {
            cout << multiplied[i] << endl;
        }
        #endif
        
        // add each value in the list with a carry bit
        int carry = 0;
        string result = "";
        for (int i = max_size - 1; i >= 0; i--) {
            int sum = 0;
            
            for (int j = 0; j < multiplied.size(); j++) {
                sum += (multiplied[j][i] - '0');
            }
            sum += carry;
            
            int digit = sum % 10;
            result.insert(0, 1, (char)(digit + '0'));
            
            carry = sum / 10;
        }
        
        if (carry != 0) {
            result.insert(0, 1, (char)(carry + '0'));
        }
        
        #ifdef VERBOSE
        cout << result << endl;
        #endif
        
        // clean up all leading zeros that could be left behind
        for (int i = 0; i < result.size(); i++) {
            if (result.size() == 1) {
                break;
            }
            else if (result[i] != '0') {
                break;
            }
            else {
                result = result.substr(1, result.size()-1);
                i--;
            }
        }
        
        return result;
    }
};

