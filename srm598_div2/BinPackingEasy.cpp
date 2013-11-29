// Paste me into the FileEdit configuration dialog

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class BinPackingEasy {
public:
   int minBins( vector <int> item ) {
     int num =0;
     vector<int> sorted;
     
     // toriaezu sort
     sort(item.begin(), item.end());
     for(int i=item.size()-1; i>=0; --i){
       sorted.push_back(item[i]);
     }
     /*
     for(int i=0; i<sorted.size(); ++i)
       cout<<sorted[i]<<','
      */;

     // main count routine
     for(int i=0; i<sorted.size(); ++i){
       int tmp = sorted[i];
       if(sorted[i] == 0)
         continue;
       
       for(int j=i+1; j<sorted.size(); ++j){
         if( (tmp+sorted[j]) <= 300){
           tmp += sorted[j];

           sorted[j] = 0;
         }
         sorted[i] = 0;
       }

       ++num;
     }
     
     return num;

   }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int item[]                = {150, 150, 150, 150, 150};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = BinPackingEasy().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int item[]                = {130, 140, 150, 160};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = BinPackingEasy().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int item[]                = {101, 101, 101, 101, 101, 101, 101, 101, 101};
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = BinPackingEasy().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int item[]                = {101, 200, 101, 101, 101, 101, 200, 101, 200};
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = BinPackingEasy().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int item[]                = {123, 145, 167, 213, 245, 267, 289, 132, 154, 176, 198};
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = BinPackingEasy().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int item[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BinPackingEasy().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int item[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BinPackingEasy().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int item[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BinPackingEasy().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
