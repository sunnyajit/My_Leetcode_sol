class ProductOfNumbers {
public:  // code written by sunny
    vector<int> products;   
    ProductOfNumbers() {
        products.push_back(1);   
    }
    
    void add(int num) {
        if (num == 0) {
            products.clear();   
            products.push_back(1);   
        } else {
             products.push_back(products.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = products.size();
        if (n <= k) {
            return 0; 
        }
 
        return products[n - 1] / products[n - 1 - k];
    }
};
