#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include "definelog.h"

#define kTimeFormatLenth 32
static char curTime[kTimeFormatLenth] = { 0 };

static int getCurrentTmie(void)
{	
	struct tm tmTime = { 0 };
	size_t timeLen = 0;
	time_t tTime = 0;

	tTime = time(NULL);
	localtime_s(&tmTime, &tTime);
	//timeLen = strftime(curTime, 33, "%Y(Y)%m(M)%d(D)%H(H)%M(M)%S(S)", tmTime);
	timeLen = strftime(curTime, 33, "%Y-%m-%d %H:%M:%S", &tmTime);
	return timeLen;
}

static void openLogFile(const char* log, int len)
{
	int ret = system("cd log");
	if (0 != ret){
		ret = system("mkdir log");
		if (0 != ret){
			return;
		}
	}
	
	char fileNameBuf[kLineInfoMaxLenth] = { 0 };
	sprintf_s(fileNameBuf, kLineInfoMaxLenth, kDefaultLogFilePath, "test");
	FILE *pf = NULL;
	fopen_s( &pf, fileNameBuf, "a+");
	if (NULL == pf){
		return;
	}
	int tmLen = getCurrentTmie();
	fwrite(curTime, tmLen, 1, pf);
	memset(curTime, 0, kTimeFormatLenth);
	fwrite(log, len, 1, pf);
	fclose(pf);
}