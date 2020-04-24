public class solution {
    public int maxProfit(int prices[]) {
        int minprice = Integer.MAX_VALUE;
        int maxprofit = 0;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
    }

/*
Complexity Analysis

Time complexity : O(n). Only a single pass is needed.

Space complexity : O(1). Only two variables are used.
    
Say the given array is:

[7, 1, 5, 3, 6, 4]

We need to find the lowest buying price and the highest selling price. Store those in two variables,
minprice and maxprofit, then we can find the difference between them when the loop finishes.
*/
    
}
