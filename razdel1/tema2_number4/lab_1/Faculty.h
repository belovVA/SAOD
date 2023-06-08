#pragma once
#include "CompGroup.h"
#include <iostream>
#include <string>

using namespace std;

class Faculty
{
private:
	string headline;
	CompGroup Subgroupes;
public:
	Faculty(string _headline) { headline = _headline; }
	Faculty() { headline = "Факультет"; }
	void SetHeadLine(string _headline) { headline = _headline; }
	string GetHeadline() { return headline; }

};