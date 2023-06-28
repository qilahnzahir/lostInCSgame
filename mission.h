#ifndef MISSION_H
#define MISSION_H
#include <iostream>
#include <string>
using namespace std;

class Mission
{
	private:
		string question;
		string answer;
		bool missionCompleted;
	public:
		Mission(){}
		Mission(string q, string a)
		{
			question=q;
			answer=a;
			missionCompleted=false;
		}
		~Mission(){}
		bool checkAnswer(string &playerAnswer)   //LecturerRoom
		{

  			if ( playerAnswer == answer ) //cout<<your answer is..
                return true;
            else
                return false;

  	}
		string getMission()
		{
			return question;
		}
		void markMissionCompleted()
		{
			missionCompleted=true;
		}
		bool isMissionCompleted()
		{
			return missionCompleted;
		}

	};
#endif
