// Syntax_Scoring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

pair<long long, long long> analyse_line(string& line)
{
    pair<long long, long long> pair;
    vector<char> v;
    vector<char> opening_braces = {'(', '[', '{', '<'};
    unordered_map<char, char> m = {{')', '('},{']', '['},{'}', '{'},{'>', '<'},{'(', ')'},{'[', ']'},{'{', '}'},{'<', '>'}};
    unordered_map<char, long long> syntax_scr = {{')', 3LL},{']', 57LL}, {'}', 1197LL}, {'>', 25137LL}};

    unordered_map<char, long long> score = {{')', 1LL},{']', 2LL},{'}', 3LL},{'>', 4LL}};

    auto syntax_score = 0LL;
    auto total_score = 0LL;

    for (auto c: line) {

        auto itr = find(opening_braces.begin(), opening_braces.end(),c);
        if (itr!= opening_braces.end())
            v.push_back(c);

        else if (v.back() == m[c])
            v.pop_back();

        else{  // if first illegal character found break the for loop
            syntax_score = syntax_scr[c];
            break;
        }
    }

    while (!v.empty())  //we have all the open brackets without a pair in the vector
    {
        total_score = 5 * total_score + score[m[v.back()]];
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


