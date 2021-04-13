#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector <vector <pair <string, int> > > score;
vector <string> jobb;

struct Res{
	string job;
	int score;
	
	res(string job, int score){
		this->job = job;
		this->score = score;
	}
	
	bool operator>(const Res &a)const{
		if(score != a.score) return score > a.score;
		if(job != a.job) return job < a.job;
	}
};

string solution(vector <string> table, vector <string> languages, vector <int> preference);
void split(vector <string> table);
string calculate(vector <string> languages, vector <int> preference);

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector <string> ta = { "SI JAVA JAVASCRIPT SQL PYTHON C#", 
	"CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", 
	"HARDWARE C C++ PYTHON KOTLIN PHP", 
	"PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", 
	"GAME C++ C# JAVASCRIPT C JAVA"};
	vector <string> languages = {"PYTHON", "C++", "SQL"};
	vector <int> preference = {7,5,5};
	
	
	cout << solution(ta, languages, preference);
	
	return 0;
}

string solution(vector <string> table, vector <string> languages, vector <int> preference){
	
	string result;
	split(table);
	
	result = calculate(languages,preference);
	
	return result;
}

void split(vector <string> table){
	
	for(int i = 0; i < 5; i++){
		char str[] = table[i];
		char *ptr = strtok(str, " ");
		jobb.push_back(ptr);
		int num = 5;
		while(ptr != NULL){
			*ptr = strtok(NULL, " ");
			score.push_back({ptr,num});
			num--;
		}
	}
}

string calculate(vector <string> languages, vector <int> preference){
	
	vector <Res> res;
		
	for(int i = 0; i < 5; i++){
		int sum = 0;
		for(int j = 0; j < languages.size(); j++){
			for(int k = 0; k < 5; k++){
				if(langugase[j] == score[i][k].first){
					sum += score[i][k].second * preference[j];
				}
			}
		}
		res.push_back(Res(jobb[i], sum));
	}
	sort(res.begin(), res.end());
	
	return res[0].job;
}
