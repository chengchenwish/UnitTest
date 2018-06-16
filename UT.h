#pragma once
#include <string>
#include<vector>
#include<iostream>
using namespace std;

class assertException
{
};
class UT  
{
public:
	typedef void(*function)();
	 static void  printCaseInfo(const std::string& caseName);
	 static void printErrorInfo( );
	static void addCase (function f);
	static void runTest();
	std::vector<int> ll;

//private:
	//std::vector<void(*)()>caseList_;



};

#define ASSERT_TRUE(CONDITION)\
	    do                    \
		{						\
		if(!(CONDITION))throw assertException(); 			\
		 }while(0)						\


																				\

#define TEST_CASE(NAME)  class CASEEXCUTOR_##NAME \
       {	\
          public:\
          static void runCase()\
          {						\
	         UT::printCaseInfo(#NAME);\
	        testCase_##NAME();  			              \
           }					                      \
		     CASEEXCUTOR_##NAME()\
			 { \
			 UT::addCase(&CASEEXCUTOR_##NAME::runCase);\
																				}\
																					\
			friend static void testCase_##NAME();\
			};CASEEXCUTOR_##NAME NAME##instance; 						\
			void  testCase_##NAME()	\


