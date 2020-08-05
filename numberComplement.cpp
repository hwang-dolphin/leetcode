ass Solution {
public:
    int findComplement(int num) 
    {
        unsigned int counter = 0;
           
        int leftMostPos;
        
        for (int i = 31; i >= 0; i--)
        {
            if ((num & (1 << i)) != 0)
            {
                leftMostPos = i;
                break;
            }
        }
        
  	// 31 bits to avoid overflow 
	// 0 based     
        for (int i = 0; i <= leftMostPos; i++)
        {
            if ((num & (1 << i)) == 0)
            {
                counter = counter + pow(2, i);
            }
        }
        
        return counter;
    }
};
