#include <vector>
#include <map>
#include <cassert>
#include <iostream>

class Solution {
public:
  int findJudge(int N, std::vector<std::vector<int>> &Trust) {

    std::vector<int> TrustCounter(N, 0);
    std::vector<bool> ValidJudge(N, true);

    int Count = 0;
    int X = -1;

    for (const auto &Person : Trust) {
      TrustCounter[Person[1] - 1] ++;
      if (TrustCounter[Person[1] - 1] == N - 1) {
        Count++;
        X = Person[1];
        // no judge
        if (Count >= 2) {
          return -1;
        }
      }
      // judge trusts nobody
      ValidJudge[Person[0] - 1] = false;
    }
    if (Count == 0) {
      return N == 1 ? 1 : -1;
    }
    if (ValidJudge[X - 1]) {
      return X;
    }
    return -1;
  }
};

// test 1
void test01() {
  std::cout << "  Test 1\n";

  Solution S1;
  std::vector<std::vector<int>> TownFolk;

  // std::vector<int> P1;
  TownFolk.push_back(std::vector<int>());
  TownFolk[0].push_back(1);
  TownFolk[0].push_back(2);
  int N = 2;

  //TownFolk.push_back(P1);
  int Judge = S1.findJudge(N, TownFolk);
  // solution: 2
  assert(Judge == 2);
  std::cout << "The Judge is person " << Judge << std::endl;
}

// test 2
void test02() {
  std::cout << "  Test 2\n";

  Solution S1;
  std::vector<std::vector<int>> TownFolk;

  TownFolk.push_back(std::vector<int>());
  TownFolk[0].push_back(1);
  TownFolk[0].push_back(3);
  TownFolk.push_back(std::vector<int>());
  TownFolk[1].push_back(2);
  TownFolk[1].push_back(3);

  int N = 3;

  // TownFolk.push_back(P1);
  // TownFolk.push_back(P2);

  int Judge = S1.findJudge(N, TownFolk);
  // solution: 3
  assert(Judge == 3);
  std::cout << "The Judge is person " << Judge << std::endl;
}

// test 3
void test03() {
  std::cout << "  Test 3\n";
  Solution S1;
  std::vector<std::vector<int>> TownFolk;

  TownFolk.push_back(std::vector<int>());
  TownFolk[0].push_back(1);
  TownFolk[0].push_back(3);
  TownFolk.push_back(std::vector<int>());
  TownFolk[1].push_back(2);
  TownFolk[1].push_back(3);
  TownFolk.push_back(std::vector<int>());
  TownFolk[2].push_back(3);
  TownFolk[2].push_back(1);

  int N = 3;

  int Judge = S1.findJudge(N, TownFolk);
  // solution: -1
  assert(Judge == -1);
  std::cout << "The Judge is person " << Judge << std::endl;
}

// test 4
void test04() {
  std::cout << "  Test 4\n";
  Solution S1;
  std::vector<std::vector<int>> TownFolk;

  TownFolk.push_back(std::vector<int>());
  TownFolk[0].push_back(1);
  TownFolk[0].push_back(2);
  TownFolk.push_back(std::vector<int>());
  TownFolk[1].push_back(2);
  TownFolk[1].push_back(3);

  int N = 3;

  int Judge = S1.findJudge(N, TownFolk);
  // solution: -1
  assert(Judge == -1);

  std::cout << "The Judge is person " << Judge << std::endl;
}

// test 5
void test05() {
  std::cout << "  Test 5\n";
  Solution S1;
  std::vector<std::vector<int>> TownFolk;

  TownFolk.push_back(std::vector<int>());
  TownFolk[0].push_back(1);
  TownFolk[0].push_back(3);
  TownFolk.push_back(std::vector<int>());
  TownFolk[1].push_back(1);
  TownFolk[1].push_back(4);
  TownFolk.push_back(std::vector<int>());
  TownFolk[2].push_back(2);
  TownFolk[2].push_back(3);
  TownFolk.push_back(std::vector<int>());
  TownFolk[3].push_back(2);
  TownFolk[3].push_back(4);
  TownFolk.push_back(std::vector<int>());
  TownFolk[4].push_back(4);
  TownFolk[4].push_back(3);

  int N = 4;

  int Judge = S1.findJudge(N, TownFolk);
  // solution: 3
  assert(Judge == 3);
  std::cout << "The Judge is person " << Judge << std::endl;
}
int main() {
  // test 1
  test01();

  // test 2
  test02();

  // test 3
  test03();

  // test 4
  test04();

  // test 5
  test05();

  return 0;
}