#pragma once
#include <string>
#include<vector>
#include<iostream>
#include<functional>

using namespace std;

class assertException { };

class UT
{
public:
	using function = std::function<void(void)>;
	static void  printCaseInfo(const std::string& caseName);
	static void printErrorInfo();
	static void addCase(function f);
	static void runAllTest();
	static std::vector<function>*caseList_;
};

#define ASSERT_TRUE(CONDITION)\
		do\
		{						\
			if(false==(CONDITION))throw assertException(); 			\
		 }while(0)						\


#define TEST_CASE(NAME)  \
		class CASEEXCUTOR_##NAME \
       {	\
          public:\
          static void runCase()\
          {						\
	         UT::printCaseInfo(#NAME);\
	        testCase_##NAME();  			              \
           }					                      \
		   CASEEXCUTOR_##NAME()\
		  { \
	   		UT::addCase(std::bind(CASEEXCUTOR_##NAME::runCase));\
		  }\
			static void testCase_##NAME();																		\
		};CASEEXCUTOR_##NAME NAME##instance; 						\
		void CASEEXCUTOR_##NAME :: testCase_##NAME()	\


