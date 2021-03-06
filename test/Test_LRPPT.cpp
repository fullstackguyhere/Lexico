/*
Author 		: 	Lv Yang
Created 	: 	20 December 2016
Modified 	: 	28 December 2016
Version 	: 	1.0
*/

/* This file used to test the class 'LRPPT' */

#include <iostream>
using std::cout;

#include "../grammar/LRPPT.h"
using Seven::Grammar;
using Seven::LRPPT;


/* test build LRPPT */
void test_1()
{
	const char * path_input = "/home/seven/gitspace/compiler/bin/lex_res.log";
	const char * path_res = "/home/seven/gitspace/compiler/bin/grammar_res.log";
	const char * path_error = "/home/seven/gitspace/compiler/bin/grammar_error.log";

	LRPPT * ppt = LRPPT::create();
	ppt->print(cout);

	delete ppt;
}


int main()
{
	Grammar::init("/home/seven/gitspace/compiler/conf/production.conf");
	test_1();
	return 0;
}
