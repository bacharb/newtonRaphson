#define BOOST_TEST_MODULE Regression

#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test1_suite)

BOOST_AUTO_TEST_CASE(Test1){
    BOOST_CHECK(2 < 7);
}

BOOST_AUTO_TEST_CASE(Test2){
    BOOST_CHECK(2 < 788);
}

BOOST_AUTO_TEST_SUITE_END()
