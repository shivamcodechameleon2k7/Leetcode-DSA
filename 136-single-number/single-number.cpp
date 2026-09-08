class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int appear = 0;
        for (int i : nums){
            appear = appear^i;
            //  XOR has two important properties:
            // a ^ a = 0 → two identical numbers cancel each other.
            //  a ^ 0 = a → the remaining number stays.
            // although a^a = 0, if we have (a^b^c^d^a^b^c) , XOR will still be applicable by using commutative property of maths that arranges the XOR elements one by one with same elements which then looks like (a^a^b^b^c^c^d) this means all the same element will result to zero and only d remains cause it has no other element for itself to make any pair.
        }
        return appear;
    }
};