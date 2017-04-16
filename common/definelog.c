#include "definelog.h"

static const char* getCurrentTmie(void)
{
	static char curTime[32] = { 0 };
	struct tm tmTime = { 0 };
	size_t timeLen = 0;
	time_t tTime = 0;

	tTime = time(NULL);
	localtime_s(&tmTime, &tTime);
	//timeLen = strftime(curTime, 33, "%Y(Y)%m(M)%d(D)%H(H)%M(M)%S(S)", tmTime);
	timeLen = strftime(curTime, 33, "%Y-%m-%d %H:%M:%S", &tmTime);
	return curTime;
}