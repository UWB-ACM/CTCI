#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *generateTest();

// SIMPLE_SOLUTION
class SimpleSolution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *Edge, *PreLBound, *UBound;
        // create edging node
        Edge= new ListNode(0);
        Edge->next = head;
        PreLBound = Edge;
        UBound = head;
        int Sum=0;
        while(UBound)
        {
            Sum = Sum + UBound->val;
    
            // if found zero sum range [LBound,UBound]
            // where LBound == PreLBound->Next;
            // then re-link from Prev to UBound->Next
            if(Sum == 0) {
                PreLBound->next = UBound->next;
            }
            UBound = UBound->next;
            // no zero-sum found in the range [Prev, End]
            // continue checking from [Prev->next, End]
            if(UBound == NULL)
            {
                PreLBound = PreLBound->next;
                // end of list
                if(PreLBound == NULL) break;
                UBound = PreLBound->next;
                Sum=0;
            }
        }
        // returning the result without the edging node
        return Edge->next;
    }
};

// OPTIMAL SOLUTION
class OptimalSolution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        // create edging node. Reason explained above.
        ListNode* Edge =new ListNode(0);
        Edge->next=head;
        // unordered map is faster with inserting/removing
        unordered_map<int,ListNode*> SumMap;
        SumMap[0] = Edge;
        int Sum = 0;

        while(head != nullptr){
            Sum += head->val;
            // if found zero-sum range: [LBound,head]
            // then delete from SumMap Sums recorded between [LBound,head]
            // then re-link from Prev to UBound->Next
            if(SumMap.find(Sum) != SumMap.end()) {
                ListNode *PrevLBound = SumMap[Sum];
                ListNode *Cur = PrevLBound;

                //delete Sums recorded in range [LBound, head]
                int subSum = Sum;
                while(Cur != head){
                    Cur = Cur->next;
                    subSum += Cur->val;
                    if(Cur != head) SumMap.erase(subSum);
                }
                // remove nodes from Lbound to head
                PrevLBound->next = head->next;
            } else {
                // if zero-sum range NOT exist
                // record Sum for further tracking
                SumMap[Sum] = head;
            }
            // examine next node
            head = head->next;
        }
        // returning the result without the edging node
        return Edge->next;
    }
};
void printList(ListNode *Result) {
    // print out result
    while (Result != nullptr) {
        cout << Result->val;
        Result = Result->next;
        if (Result != nullptr) cout << " ";
    }
    cout << "]\n";
}

int main(int argc, const char * argv[]) {
    ListNode *List = generateTest();
    ListNode *Result;
    
    cout << "Input:\t[";
    printList(List);
    
    // add your code here or uncomment one of these solutions
    // Result = .....
    
    // Result = SimpleSolution().removeZeroSumSublists(List);
    Result = OptimalSolution().removeZeroSumSublists(List);
    
    cout << "Output:\t[";
    printList(Result);
    
    return 0;
}

// Ignore this section. It is for testing only!
ListNode *generateTest() {
    srand(time(NULL));
    int N = rand() % 10 + 5;
    ListNode *List = new ListNode(rand() % 100 - 100);
    ListNode *Cur = List;
    int sum = 0;
    for (auto I = 0; I < N - 1; I++) {
        auto val = rand() % (2 * N + 1);
        if (abs(sum) > rand() % (rand() % N + N)) {
            Cur->next = new ListNode(sum*-1);
            sum = rand()%N;
        }
        else {
            sum += val;
            Cur->next = new ListNode(val);
        }
        Cur = Cur->next;
    }
    return List->next;
}
