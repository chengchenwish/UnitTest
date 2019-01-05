#include "UT.h";
#include "pch.h"


std::vector<UT::function>* UT::caseList_ = nullptr;

void UT::printCaseInfo(const std::string& caseName)
{
	std::cout << "TEST CASE :" << caseName << endl;
}
void UT::printErrorInfo()
{
	std::cout << "ERROR_INFO:FILE=" << __FILE__ << " LINE=" << __LINE__ << std::endl;


}
void UT::addCase(function f)
{

	if (caseList_ == nullptr)
	{
		caseList_ = new std::vector<function>;
	}
	caseList_->push_back(f);	
	
}
void UT::runAllTest()
{
	if (caseList_ == nullptr)
	{
		return;
	}
	uint32_t passed = 0;
	try
	{
		for (auto& caseExcutor : *caseList_)
		{
			caseExcutor();
			passed++;
		}
	}
	catch (assertException)
	{
		printErrorInfo();
	}
	std::cout << "################################################" << std::endl;
	std::cout << "Passed case is:" << passed << "  Total case is :" << caseList_->size() << std::endl;
	delete caseList_;

}
