#include <incl.hpp>
#include <testDerivative.hpp>
#include <testNewtonRaphson.hpp>

CPPUNIT_TEST_SUITE_REGISTRATION(TestDerivative);
CPPUNIT_TEST_SUITE_REGISTRATION(TestNewtonRaphson);

int main(int argc, char* argv[]) {
	
	TestResult testresult;
	TestResultCollector collectedresults;
	
	testresult.addListener (&collectedresults);

	BriefTestProgressListener progress;
	testresult.addListener (&progress);

	TestRunner testrunner;
	testrunner.addTest (TestFactoryRegistry::getRegistry().makeTest ());
	
	testrunner.run(testresult);

	CompilerOutputter compileroutputter(&collectedresults, cerr);
	compileroutputter.write ();

	ofstream xmlFileOut("cppTestDerivativeResults.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();

	return collectedresults.wasSuccessful() ? 0 : 1;
}

