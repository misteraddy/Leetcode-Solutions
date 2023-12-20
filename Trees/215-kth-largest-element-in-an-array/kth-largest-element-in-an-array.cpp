class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        //error resolved 2:
        
        priority_queue<int,vector<int>,greater<int>> pq ;
        
        //min heap banane k liye priority queue
        
        //min heap issilye use kar rahe kyunki elements mei toh mei minimum element hoga 
        //aur minimum element ko remove karke hum usse bada element add karenge 
        //jiske karan aakhiri mei bas sabse bade element in the order bachenge.
        
        for(int i = 0 ; i < k ; i++)
        {
            int element = nums[i];
            pq.push(element);
        }
        
        //error resolved 1:
        
        for(int i = k ; i < nums.size() ; i++)
        {
            int element = nums[i];
            
            if(element > pq.top())
            {
                pq.pop();
                pq.push(element);
            }
        }
        
        int ans = pq.top();
        
        
        return ans ;
    }
};

//ERROR THAT I MADE 
/*

max heap use karne ki soch raha tha mai .

k + 1 le k chal rha tha jabki starting k se hogi second loop mei

*/

// APPROACH
/*
The approach involves using a min-heap implemented with a priority queue.

Initially, we populate the min-heap with the first k elements of the input vector 'nums'.

Then, we iterate over the remaining elements of 'nums' and update the min-heap by comparing each element with the top of the heap.

If an element is greater than the top of the heap, we remove the smallest element from the heap and insert the current element.

After processing all elements, the top of the min-heap contains the kth largest element.
*/

// THINGS YOU LEARNED
/*
1. Priority queues can be used to efficiently maintain the k smallest or k largest elements.
2. Min-heap, implemented using a priority queue with a greater comparison function, is useful for finding the kth largest element.
3. The top element of the min-heap is always the smallest among the elements currently in the heap.
4. priority_queue<int> pq -> max heap
     priority_queue<<int>,vector<int>,greater<int>> pq  -> min heap
     
5. kyunki element ko insert karte karte with condition at the end joh remaining element
    honge will all be the greatest element 
    
    insert hi top element se bade wale honge aage wale loop mei

*/

// CORNER CASES
/*
- The code assumes that the input vector 'nums' has at least k elements.
- The behavior for cases where k is larger than the size of 'nums' is not defined in the provided code. It's important to handle such cases appropriately based on the requirements.
*/

// TIME COMPLEXITY - O(N log K)
/*
The time complexity is O(N log K), where N is the size of the input vector 'nums'. The first loop to populate the min-heap takes O(K log K) time, and the second loop to iterate over the remaining elements takes O((N-K) log K) time, as each insertion or removal operation on the min-heap takes O(log K) time.
*/

// SPACE COMPLEXITY - O(K)
/*
The space complexity is O(K), where K is the input parameter representing the kth largest element to be found. The space is used to store the k elements in the priority queue.
*/
