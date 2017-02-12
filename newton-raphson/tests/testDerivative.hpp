#pragma once
#include <incl.hpp>

class TestDerivative : public TestFixture{
   CPPUNIT_TEST_SUITE(TestDerivative);
   CPPUNIT_TEST(test_general);
   CPPUNIT_TEST(test_stability);
   CPPUNIT_TEST_SUITE_END();

   public:
   void setUp(void) {derivative = new TwoPointDerivative ();}
   void tearDown(void) {delete derivative;}

   protected:
   void test_stability(void);
   void test_general(void);

   private:
   static Real g (Real x) {return sin(x) ;}  
   static constexpr Real h  = 0.001;
   static constexpr Real x0 = 1.0466666666666666;
   Derivative *derivative;

   class Afunction {
      public:
         Real operator ()(Real x) {return sin(x);}
   };  
};
