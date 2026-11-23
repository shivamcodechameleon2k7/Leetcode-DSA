
class ProductOfNumbers {
public:
    vector<int> prefix;

    ProductOfNumbers() {
        prefix.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
        }
        else {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefix.size();

        if (k >= n) {
            return 0;
        }

        return prefix[n - 1] / prefix[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

 /*
 1. prefix.push_back(1) – initialize the prefix product.
2. prefix.back() * num – multiply the previous prefix product by the new number.
3. If num == 0, reset the vector because products containing zero become zero.
4. If k >= n, return 0 because a zero exists within the last k numbers.
5. Otherwise, divide the total prefix product by the prefix product before the last k elements.
Complexity
- add(num) → O(1)
- getProduct(k) → O(1)
- Space → O(n), where n is the number of additions since the last zero.*/