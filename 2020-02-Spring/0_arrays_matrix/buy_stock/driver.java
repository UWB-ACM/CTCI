public class driver{
    public static void main(String [] args){
        solution sol = new solution();
        int [] arr1 = {3};
        int [] arr2 = {1,9};
        int [] arr3 = {8,1};
        int [] arr4 = {7,1,5,3,6,4};
        int [] arr5 = {6,1,1,23,4,54,33,4,1,9,2,3,4,5,9,6,4,5,3,100};

        Test("Max profit for arr1 is " + maxProfit(arr1), maxProfit(arr1) == 0);
        Test("Max profit for arr2 is " + maxProfit(arr2), maxProfit(arr2) == 8);
        Test("Max profit for arr3 is " + maxProfit(arr3), maxProfit(arr3) == 0);
        Test("Max profit for arr4 is " + maxProfit(arr4), maxProfit(arr4) == 5);
        Test("Max profit for arr5 is " + maxProfit(arr5), maxProfit(arr5) == 99);

    }

    //Your solution here
    public static int maxProfit(int prices[]) {
        return maxprofit;
    }

    //For testing
    public static void Test(String testDescription, boolean testPasses) {
		if (testPasses)
			System.out.println("Test PASSED: " + testDescription);
		else
			System.out.println("Test FAILED: " + testDescription);
	}
}
