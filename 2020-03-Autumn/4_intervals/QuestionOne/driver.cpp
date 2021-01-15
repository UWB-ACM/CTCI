#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    // first check if the intervals vector is empty
    if (intervals.size() == 0 ) {
        return {newInterval};
    }
    //start of the new interval
    int newStart = newInterval[0];
    // End of the new interval
    int newEnd = newInterval[1];
    //index to use to iterate through intervals
    int i = 0;
    //vector of vectors to return
    vector<vector<int>> res;
    int size = intervals.size();

    //Add the intervals whose starting time is less than the new interval starting time
    //into the res vector
    while (i < size && newStart > intervals[i][0]) {
        res.push_back(intervals[i++]);
    }
    //we will use this interval vector as a temp holder of intervals
    vector<int> interval(2);

    //if there is no overlap, then add the new interval
    //An overlap happens if the end time of the last interval in res is greater than the new interval start time
    if (res.size() == 0 || res[res.size() - 1][1] < newStart) {
        res.push_back(newInterval);
    } else {
        //Otherwise, if there is an overlap, merge with the last interval in res
        vector<int> temp = res[res.size() - 1];
        res.pop_back();
        interval[0] = temp[0];
        interval[1] = max(temp[1],newEnd);
        res.push_back(interval);
    }

    // Add new intervals, and merge with newInterval if the intervals overlap
    while (i < size) {
        vector<int> temp = intervals[i++];
        //start time of the temp interval
        int start = temp[0];
        //end time of the temp interval
        int end = temp[1];

        //Check for overlap
        //If the start time of temp is greater than the end time of the last interval in res
        //It means there is no overlap
        if (res[res.size() - 1] [1] < start){
            res.push_back(temp);
        }else{
            //Else we need to update the last interval in res
            //to have the latest end time between the current end time
            //and temp end time
            interval = res[res.size() - 1];
            res.pop_back();
            interval[1] = max(interval[1], end);
            res.push_back(interval);
        }

    }
    return res;
}

void printOutput(const vector<vector<int>> &list){

    for (int i = 0 ; i < list.size(); i++) {
        cout << "[ " << list[i][0] << ", " << list[i][1] <<" ]" <<endl;
    }

}
int main() {

    vector<vector<int>> intervals;
    //For now we are just testing with two intervals
    vector<int> interv1;
    vector<int> interv2;
    //Adding data into the intervals
    interv1.push_back(1);
    interv1.push_back(3);
    interv2.push_back(6);
    interv2.push_back(9);
    //Pushing the intervals into the intervals vector
    intervals.push_back(interv1);
    intervals.push_back(interv2);
    //Creating the new interval
    vector<int> newInterval;
    newInterval.push_back(2);
    newInterval.push_back(5);

    vector<vector<int>> output = insert(intervals, newInterval);
    //Printing out the intervals with the new interval inserted
    cout << "Result intervals:" <<endl;
    printOutput(output);



    return 0;
}
