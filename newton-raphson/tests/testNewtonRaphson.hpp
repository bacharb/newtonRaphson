#include <incl.hpp>


const Real pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;
class TestNewtonRaphson: public TestFixture{
   CPPUNIT_TEST_SUITE(TestNewtonRaphson);
   CPPUNIT_TEST(test_polynomialFun);
   CPPUNIT_TEST(test_trigonometrcFun);
   CPPUNIT_TEST(test_racineDe2);
   CPPUNIT_TEST_SUITE_END();

   public:
   void setUp(void) {}
   void tearDown(void) {}

   protected:
   void test_racineDe2(void);
   void test_polynomialFun(void);
   void test_trigonometrcFun(void);
};
