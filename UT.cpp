#include "UT.h";


struct FuncList
{
	FuncList*next;
	UT::function f ;
	FuncList():next(nullptr),f(nullptr)
	{
	}
};
FuncList*head=nullptr;
FuncList *tail =head;

 void UT::printCaseInfo(const std::string& caseName)
 {
	 std::cout<<"TEST CASE :"<<caseName<<endl;
 }
 void UT::printErrorInfo( )
 {
	 std::cout<<"ERROR_INFO:FILE="<<__FILE__<<" LINE="<<__LINE__<<std::endl;

	 
 }
 void UT::addCase(function f)
 {
	
	// UT::ll.push_back(40);
	// tt=f;
	// f();
	 if(!head)
	 {
		 head = new FuncList();
		 head->f = f;
		 tail = head;
	 }else
	 {
		 tail->next = new FuncList();
		 tail= tail->next;
		 tail->f = f;

	 }
	 

 }
 void UT::runTest()
 {
	 try
	 {
	while(head)
	{
		head->f();
		head=head->next;
	 }
	 }
	 catch(assertException)
	 {
		 UT::printErrorInfo();
		 while(head)
	{
		FuncList* p =head;
		head=head->next;
		delete p;
	 }
		 return;
	 }
	  while(head)
	{
		FuncList* p =head;
		head=head->next;
		delete p;
	 }
 }
