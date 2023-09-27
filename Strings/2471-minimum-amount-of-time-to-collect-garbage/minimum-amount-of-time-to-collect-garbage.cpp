class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        //these are the picking time of garbage by each truck type
        int picking_Time_P = 0 ;
        int picking_Time_M = 0 ;
        int picking_Time_G = 0 ;
        
        //these are the last house till which the truck gather the garbage
        //these are used to calculate the travel time
        int last_house_P = 0 ;
        int last_house_M = 0 ;
        int last_house_G = 0 ;
        
        //time in travelling
        int travel_time_P = 0 ;
        int travel_time_M = 0 ;
        int travel_time_G = 0 ;
        
        
        //index denotes the house and garbage array is traversed 
        for(int i = 0 ; i < garbage.size() ; i++)
        {
            //the garbage type in string Ex - P or M or G
            string cur = garbage[i];
            
            
            // traversing the current string
            for(int j = 0 ; j < cur.length() ; j++)
            {
                char ch = cur[j];
                
                //checking whether P or M or G
                if(ch == 'P')
                {
                    picking_Time_P++;
                    //updating the house number last visited by particular truck 
                    last_house_P = i ;
                }
                
                else if(ch == 'M')
                {
                    picking_Time_M++;
                    last_house_M = i ;
                }
                
                else if(ch == 'G')
                {
                    picking_Time_G++;
                    last_house_G = i ;
                }
                
                
            }
             
        }
        
        //calculating travel time 
        //jis ghar tak gye hai 
        //vaha tak ki indexes ki values ka sum
        //kyunki ek value ye bata rahi hai ki i se agle ghar k beech mei kitni doori
        for(int i = 0 ; i < last_house_P ; i++)
            {
                travel_time_P += travel[i];
            }
            
            for(int i = 0 ; i < last_house_M ; i++)
            {
                travel_time_M += travel[i];
            }
            
            for(int i = 0 ; i < last_house_G ; i++)
            {
                travel_time_G += travel[i];
            }
        
         int total = (picking_Time_P + picking_Time_M + picking_Time_G) + (travel_time_P + travel_time_M + travel_time_G) ;
        
        return total ;
    }
};