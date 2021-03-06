/*
Author 		: 	Lv Yang
Created 	: 	09 November 2016
Modified 	: 	14 December 2016
Version 	: 	1.0
*/

/* This file used to test the class 'NFA' */

#include "../lexical/NFA.h"
using Seven::NFA;
using Seven::FANode;

#include "../lexical/Regex.h"
using Seven::Regex;

#include "../lexical/RegexConf.h"
using Seven::RegexConf;

#include <queue>
using std::queue;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;

/* print a FANode */
void show(FANode & node)
{
	cout<<"this node itself :\n";
	cout<<'\t'<<(void *)&node<<'\t';
	cout<<node.getId()<<'\t';
	cout<<node.getType()<<'\t';
	cout<<node.getMean()<<'\n';
	cout<<"next nodes :\n";
	size_t n = node.getEdges()->size();
	for(size_t i = 0; i < n; i++){
		cout<<'\t'<<(void *)(node.getNexts()->at(i))<<'\t';
		cout<<"id : "<<node.getNexts()->at(i)->getId()<<"\t\t";
		cout<<"type : "<<node.getNexts()->at(i)->getType()<<'\t';
		cout<<"mean : "<<node.getNexts()->at(i)->getMean()<<'\t';
		cout<<"edge : "<<node.getEdges()->at(i)<<'\n';
	}
	cout<<'\n';
}


/* traverse a NFA */
bool contains(const vector<FANode *> & pool, FANode * node){
	size_t n = pool.size();
	for(size_t i = 0; i < n; i++){
		if(pool[i] == node)
			return true;
	}
	return false;
}
void traverse(const NFA & nfa){
	cout<<"print start node :\n";
	if(nfa.getStart() != NULL)
		show(*(nfa.getStart()));
	else
		cout<<"null\n";

	cout<<"print end node :\n";
	if(nfa.getEnd() != NULL)
		show(*(nfa.getEnd()));
	else
		cout<<"null\n";

	cout<<"print all nodes :\n";
	queue<FANode *> Q;
	if(nfa.getStart() != NULL)
		Q.push(nfa.getStart());
	vector<FANode *> pool;
	FANode * cur = NULL;
	vector<FANode *> * nexts = NULL;
	size_t n, i;
	while(Q.empty() == false){
		cur = Q.front();
		Q.pop();
		if(contains(pool, cur) == false){
			pool.push_back(cur);
			show(*cur);
			nexts = cur->getNexts();
			n = nexts->size();
			for(i = 0; i < n; i++)
				Q.push(nexts->at(i));
		}
	}
	cout<<'\n';
}


/* test build a NFA by given a suffix regex */
void test_1()
{
	// build a NFA
	string suffix("ab.c|*de|*.");
	int start_id = 1;
	NFA * nfa = NFA::create(suffix, 10, "ID", start_id);

	// print NFA
	traverse(*nfa);
	cout<<"\nnow the start_id : "<<start_id<<'\n';

	// delete
	delete nfa;
}


/* test build a big NFA by given several suffix regexs */
void test_2()
{
	// prepare some suffix regexs
	vector<string> regexs;
	regexs.push_back(Regex::transfer("(a|b)*.c"));
	regexs.push_back(Regex::transfer("a.b**.c"));

	vector<int> types;
	types.push_back(10);
	types.push_back(20);

	vector<string> means;
	means.push_back("ID");
	means.push_back("num");

	// create a big NFA
	int start_id = 1;
	NFA * nfa = NFA::create(regexs, types, means, start_id);

	// print NFA
	cout<<"start_id : "<<start_id<<'\n';
	traverse(*nfa);

	// delete
	delete nfa;
}


/* test build a big NFA by default regexs */
void test_3()
{
	RegexConf::init("/home/seven/gitspace/compiler/conf/regex.conf");
	NFA * nfa = NFA::create();

	traverse(*nfa);
	delete nfa;
}


/* test build a NFA by a infix regex */
void test_4()
{
	string suffix = Regex::transfer("(a|b)*.(\\**.(\\||\\.))*");
	cout << "suffix : " << suffix << '\n';

	int start_id = 1;
	NFA * nfa = NFA::create(suffix, 10, "ID", start_id);

	traverse(*nfa);
	cout<<"\nnow the start_id : "<<start_id<<'\n';

	delete nfa;
}


int main()
{
	// test_1();
	// test_2();
	// test_3();
	test_4();
	return 0;
}
