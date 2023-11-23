class Solution {
public:
    
    // Define a class to represent cars with position and speed
    class Car {
    public:
        int position;  // Current position of the car
        int speed;     // Speed of the car
        
        // Constructor to initialize the car with position and speed
        Car(int position, int speed) {
            this->position = position;
            this->speed = speed;
        }
    };
    
    // Comparator function to sort cars based on position in descending order
    static bool compareCars(Car& a, Car& b) {
        return a.position < b.position;
    }
    
    // Function to calculate the number of car fleets that reach the target
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        // Create a vector to store car objects
        vector<Car> cars;
        
        // Populate the vector with car objects using input position and speed
        for (int i = 0; i < position.size(); i++) {
            Car car(position[i], speed[i]);
            cars.push_back(car);
        }
        
        // Sort the cars based on their positions in descending order
        sort(cars.begin(), cars.end(), compareCars);
        
        // Use a stack to track the time it takes for each car to reach the target
        
        stack<float> timeStack;
        
        // Iterate through each car and calculate the time to reach the target
        
        for (auto car : cars) {
            float time =(target - car.position) / static_cast<float>(car.speed);
            
            // Check if there are previous cars that have the same or greater arrival time
            
            while (!timeStack.empty() && time >= timeStack.top()) {
                
                timeStack.pop();  // Remove the previous car from the stack
            }
            
            timeStack.push(time);  // Add the current car's arrival time to the stack
        }
        
        // The size of the stack represents the number of car fleets that reach the target
        return timeStack.size();
    }
};
