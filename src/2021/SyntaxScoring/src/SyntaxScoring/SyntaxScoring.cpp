// Syntax_Scoring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

auto analyse_line(string &line) //find first illegal character
{
	std::vector<char> v;
	auto syntax_score = 0LL; 

	for (auto c : line)
	{
		switch (c)
		{
		case '{':
		case '<':
		case '[':
		case '(':
			v.push_back(c);
			continue;

		case ')':
			if (v.back() != '(')
				syntax_score = 3;
			break;

		case ']':
			if (v.back() != '[')
				syntax_score = 57;
			break;

		case '}':
			if (v.back() != '{')
				syntax_score = 1197;
			break;

		case '>':
			if (v.back() != '<')
				syntax_score = 25137;
			break;

		}

		if (syntax_score) // if first illegal character found break the for loop
			break;

		v.pop_back(); // remove the item if no error
	}

	return syntax_score;
} 

int main()
{
	string line;
	auto answer = 0LL;


	std::ifstream file("input_syntax.txt"); //load the file

	while (getline(file, line)) //read each line   
	{
		auto result = analyse_line(line);
		answer += result;
	}
		
	cout << "Answer:" << answer;
}

