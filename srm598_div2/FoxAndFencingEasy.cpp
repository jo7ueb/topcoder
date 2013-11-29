// Paste me into the FileEdit configuration dialog

#include <string>
#include <vector>
using namespace std;

class FoxAndFencingEasy {
public:
   string WhoCanWin( int mov1, int mov2, int d ) {

     int c_pos = 0;
     int l_pos = d;

     (void)mov1, (void)mov2, (void)c_pos;
     
     // ciel's turn
     if(mov1 >= l_pos)
       return string("Ciel");

     // always draw
     if(mov1 == mov2)
       return string("Draw");

     
     return string("Draw");

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
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int mov1                  = 1;
			int mov2                  = 58;
			int d                     = 1;
			string expected__         = "Ciel";

			std::clock_t start__      = std::clock();
			string received__         = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int mov1                  = 100;
			int mov2                  = 100;
			int d                     = 100000000;
			string expected__         = "Draw";

			std::clock_t start__      = std::clock();
			string received__         = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int mov1                  = 100;
			int mov2                  = 150;
			int d                     = 100000000;
			string expected__         = "Draw";

			std::clock_t start__      = std::clock();
			string received__         = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int mov1                  = 100;
			int mov2                  = 250;
			int d                     = 100000000;
			string expected__         = "Liss";

			std::clock_t start__      = std::clock();
			string received__         = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int mov1                  = ;
			int mov2                  = ;
			int d                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int mov1                  = ;
			int mov2                  = ;
			int d                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int mov1                  = ;
			int mov2                  = ;
			int d                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
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
