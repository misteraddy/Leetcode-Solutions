//ERROR THAT I HAD MADE



//TIME COMPLEXITY - O(1)

//add function  -  O(1)

//product function - O(1)




//SPACE COMPLEXITY - O(N)



class ProductOfNumbers {
public:
    deque<int> queue;
    
    //ans array issilye use ho rha jaise current number jiska product ho rha
    //total pro se uska answer return kar rha .
    
    vector<int> arr;
    int size;
    int totalpro;

    ProductOfNumbers() {
        
        //at the starting , size is 0 kyunki no number is being added using 
        //the add function .
        
        //Also the totalpro cannot be 0 at starting because product 0 hi aayega
        
        size = 0;
        totalpro = 1;
    }

    void add(int num) {
        queue.push_back(num);

        //the case jab 0 aayega then product karne par sab gayab ho jayenge 
        //because multiplication with any number with 0 is 0
        //toh koi number hi nhi reh jana chahiye array k andar
        
        if (num == 0) {
            arr.clear();
        } else {
            if (arr.empty()) {
                arr.push_back(num);
                totalpro = num;
            } else {
                totalpro = totalpro * num;
                arr.push_back(totalpro);
            }
        }
    }

    int getProduct(int k) {
        size = arr.size();
        if (k > size) {
            return 0;
        }

        if (size == k) {
            return totalpro;
        }
        
        //ye tab karenge jab k ki value number of elements se choti hai
        //last k numbers ka product
        //toh kth index par joh answer tha usse divide kar denge toh answer aa 
        //jayega
        
        return totalpro / arr[size - k - 1];
    }
};


/*

Initialization:

Initialize a deque (queue) to keep track of all numbers.
Initialize a vector (arr) to store the running product of numbers encountered.
Initialize size and totalpro variables.



Adding Numbers:

When a new number is added:
Append it to the deque.
If the number is zero, clear the vector (arr).
Update the running product (totalpro) based on the new number.
If arr is not empty, multiply the new number with totalpro and add it to arr.



Calculating Product:

When calculating the product of the last k numbers:
Check if there are enough numbers in arr for the calculation.
If yes, return the overall product (totalpro) or calculate the product efficiently using arr.




Handling Zeros:

Zeros reset the product calculation, so the arr vector is cleared when encountering a zero.



Efficiency Consideration:

The approach maintains a running product, avoiding redundant calculations for subsequent products, leading to efficient queries for the product of the last k numbers.


*/



/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */