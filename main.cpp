#include <iostream>
#include "gtest/gtest.h"
#include "distance_two_line_segments.h"
#include <ctime>

#define EPS 1e-5

double get_random_coordinate() {
    return (rand() % 19927) / 100.;

}

TEST(Basic_test, line_segemnts_intersects) {
    line line1{1, 0, 0, 2, 0, 0};
    line line2{1.5, 0, 0, 1, 0, 0};
    ASSERT_NEAR(get_shortest_distance(line1, line2), 0, EPS);
}

TEST(Basic_test, line_segemnts_intersects2) {
    line line1{1, 1, 0, 0, 0, 0};
    line line2{0, 1, 0, 1, 0, 0};
    ASSERT_NEAR(get_shortest_distance(line1, line2), 0, EPS);
}

TEST(Basic_test, line_segments_parallel) {
    line line1{1.5, 2.5, 3.5, 3, 5, 7};
    line line2{1.5, 2.5, 4.5, 3, 5, 8};
    ASSERT_NEAR(get_shortest_distance(line1, line2), 0.64003, EPS);
}

TEST(Basic_test, line_segments_parallel2) {
    line line1{-8.17, 7, 0, -6.72, 9.52, 0};
    line line2{-5.69, 2.97, 0, -7.04, 0.63, 0};
    ASSERT_NEAR(get_shortest_distance(line1, line2), 4.73194, EPS);
}

TEST(Basic_test, line_segments_crossing) {
    line line1{1.64, -3, -1.53, 0.85, -3, 1.27};
    line line2{2, 0, 0, 0, 0, -2};
    ASSERT_NEAR(get_shortest_distance(line1, line2), 3., EPS);

}

TEST(Basic_test, line_segments_crossing2) {
    line line1{-4.65, 3.11, -1.5, -6.29, 5.79, 0};
    line line2{-6.29, 0.92, 0, -6.29, 3.11, 2.25};
    ASSERT_NEAR(get_shortest_distance(line1, line2), 3.07958, EPS);
}

TEST(Benchmark, segment_crossing) {
    line line1{-4.65, 3.11, -1.5, -6.29, 5.79, 0};
    line line2{-6.29, 0.92, 0, -6.29, 3.11, 2.25};
    for (size_t i = 0; i != 1000000; ++i) {
        ASSERT_NEAR(get_shortest_distance(line1, line2), 3.07958, EPS);
    }

}

TEST(Benchmark, segment_intersects) {
    line line1{1, 0, 0, 2, 0, 0};
    line line2{1.5, 0, 0, 1, 0, 0};
    for (size_t i = 0; i != 1000000; ++i) {
        ASSERT_NEAR(get_shortest_distance(line1, line2), 0, EPS);
    }

}

TEST(Benchmark, segments_parallel) {
    line line1{-8.17, 7, 0, -6.72, 9.52, 0};
    line line2{-5.69, 2.97, 0, -7.04, 0.63, 0};
    for (size_t i = 0; i != 1000000; ++i) {
        ASSERT_NEAR(get_shortest_distance(line1, line2), 4.73194, EPS);
    }

}

TEST(Benchmark, random_points) {
    line line1;
    line line2;
    srand(42);
    for (size_t i = 0; i != 1000000; ++i) {
        line1.x1 = get_random_coordinate();
        line1.x2 = get_random_coordinate();
        line1.y1 = get_random_coordinate();
        line1.y2 = get_random_coordinate();
        line1.z1 = get_random_coordinate();
        line1.z2 = get_random_coordinate();
        line2.x1 = get_random_coordinate();
        line2.x2 = get_random_coordinate();
        line2.y1 = get_random_coordinate();
        line2.y2 = get_random_coordinate();
        line2.z1 = get_random_coordinate();
        line2.z2 = get_random_coordinate();
        get_shortest_distance(line1,line2);
    }
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
