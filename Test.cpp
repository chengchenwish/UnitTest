#include "UT.h";

TEST_CASE(myfirstUT111)
{
	int a=122,b=88;
	ASSERT_TRUE(a!=b);
	int bc;
	bc=44;
}
TEST_CASE(myfirstUT)
{
	int a=88,b=88;
	ASSERT_TRUE(a==b);
	int bc;
	bc=44;
}
TEST_CASE(myfirstUT88)
{
	//int a=122,b=88;
	string ss;
	ss = "hhh";
	ASSERT_TRUE(ss=="hh");
	int bc;
	bc=44;
}
int _tmain(int argc, _TCHAR* argv[])
{
	UT::runTest();
	int a;
	cin>>a; 
	return 0;
}

