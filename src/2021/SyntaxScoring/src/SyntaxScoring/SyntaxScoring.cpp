// Syntax_Scoring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

pair<long long, long long> analyse_line(string& line) //find first illegal character
{
	std::vector<char> v;
	auto syntax_score = 0LL;
	auto total_score = 0LL;
	string s = "([{<";
	pair<long long, long long> pair;

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
	while (!v.empty())  //we have all the open brackets without a pair in the vector
	{
		total_score = total_score * 5 + s.find(v.back()) + 1;
		v.pop_back();
	}

	pair.first = syntax_score;
	pair.second = total_score;

	return pair;
}

int main()
{
	string line;
	auto answer = 0LL;
	vector<long long> total_scores;
	auto answer2 = 0LL;

	std::ifstream file("input_syntax.txt"); //load the file

	while (getline(file, line)) //read each line   
	{
		auto result = analyse_line(line);
		answer += result.first;

		if (result.first == 0)
			total_scores.push_back(result.second);
	}

	cout << "Answer:" << answer << endl;

	sort(total_scores.begin(), total_scores.end());

	//cout << "Size:" << total_scores.size() << endl;

	answer2 = total_scores[total_scores.size() / 2];

	cout << "Answer2:" << answer2 << endl;

}

