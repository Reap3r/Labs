#pragma once
const int evNothing=0;
const int evMessage=100;
const int cmdMake=1;
const int cmdAdd=2;
const int cmdDel=3;
const int cmdShow=4;
const int cmdName=5;
const int cmdQuit=6;

struct TEvent
{
	int what;
	union {
		int command;
		struct {
			int message;
			int param;
		};
	};
};
