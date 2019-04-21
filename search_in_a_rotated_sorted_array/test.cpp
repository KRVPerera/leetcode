#include<vector>
#include "../include/catch.hpp"
#include "Solution.h"

using namespace std;

TEST_CASE( "find in sorted rotated array {5,6,7,8,0,1,2,3,4}", "[extended binary search]" ) {
    std::vector<int> vrc {5,6,7,8,0,1,2,3,4};
    Solution sol;

    SECTION( "when: Not sorted" ) {
        CAPTURE(vrc);
        REQUIRE (sol.search(vrc, 0) == 4);
        REQUIRE (sol.search(vrc, 8) == 3);
    }

    SECTION( "when:sorted" ) {
        std::sort(vrc.begin(), vrc.end());
        CAPTURE(vrc);
        // 0,1,2,3,4,5,6,7,8
        REQUIRE (sol.search(vrc, 0) == 0);
        REQUIRE (sol.search(vrc, 8) == 8);
    }
}

TEST_CASE( "find in sorted rotated array {4,5,6,7,0,1,2}", "[extended binary search]" ) {
    Solution sol;
    std::vector<int> vrc {4,5,6,7,0,1,2};
    SECTION( "when: Not sorted" ) {
        CAPTURE(vrc);
        REQUIRE (sol.search(vrc, 0) == 4);
        REQUIRE (sol.search(vrc, 3) == -1);
        REQUIRE (sol.search(vrc, 8) == -1);
        REQUIRE (sol.search(vrc, 4) == 0);
        REQUIRE (sol.findPivot(vrc) == 3);
        REQUIRE (sol.search(vrc, 5) == 1);
        REQUIRE (sol.search(vrc, 6) == 2);
        REQUIRE (sol.search(vrc, 7) == 3);
    }

    SECTION( "when:sorted section" ) {
        std::sort(vrc.begin(), vrc.end());
        CAPTURE(vrc);
        REQUIRE (sol.search(vrc, 0) == 0);
        REQUIRE (sol.search(vrc, 3) == -1);
        REQUIRE (sol.search(vrc, 8) == -1);
        REQUIRE (sol.search(vrc, 4) == 3);
        REQUIRE (sol.findPivot(vrc) == 6);
        REQUIRE (sol.search(vrc, 5) == 4);
        REQUIRE (sol.search(vrc, 6) == 5);
        REQUIRE (sol.search(vrc, 7) == 6);
    }
}


TEST_CASE( "find in sorted rotated array {}", "[extended binary search]" ) {
    Solution sol;
    std::vector<int> vrc {};
    CAPTURE(vrc);
    REQUIRE (sol.search(vrc, 0) == -1);
    REQUIRE (sol.search(vrc, 3) == -1);
}

TEST_CASE( "find in sorted rotated array {1}", "[extended binary search]" ) {
    Solution sol;
    std::vector<int> vrc {1};
    CAPTURE(vrc);
    REQUIRE (sol.search(vrc, 0) == -1);
    REQUIRE (sol.search(vrc, 3) == -1);
}

TEST_CASE( "find in sorted rotated array {4,5,6,7,8,1,2,3}", "[extended binary search]" ) {
    Solution sol;
    std::vector<int> vrc {4,5,6,7,8,1,2,3};
    CAPTURE(vrc);
    REQUIRE (sol.search(vrc, 8) == 4);
}

TEST_CASE( "find in sorted rotated array {5,1,2,3,4}", "[extended binary search]" ) {
    Solution sol;
    std::vector<int> vrc {5,1,2,3,4};
    CAPTURE(vrc);
    REQUIRE (sol.search(vrc, 1) == 1);
}


TEST_CASE( "find pivot sorted rotated array {5,1,2,3,4}", "[findPivot]" ) {
    Solution sol;
    std::vector<int> vrc {5,1,2,3,4};
    CAPTURE(vrc);
    REQUIRE (sol.findPivot(vrc) == 0);
}
