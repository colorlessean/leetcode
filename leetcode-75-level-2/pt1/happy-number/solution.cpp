class Solution {
public:
    unordered_set<int> cycle;
    
    int sum_square_digits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {        
        while (n != 1) {
            // keep track of repeats and break when we detect a cycle       
            if (cycle.find(n) != cycle.end()) {
                return false;
            }
            cycle.insert(n);
            
            // replace with sum of square of digits
            n = sum_square_digits(n);
        }        
        
        return true;
    }
};
