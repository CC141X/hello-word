#ifndef DEFINELOG_H
#define DEFINELOG_H


#define kLineInfoMaxLenth 1024
#ifdef WIN32
#define kDefaultLogFilePath "log\\%s.log"
#else
#define kDefaultLogFilePath "log/%s.log"
#endif

#define _DEBUG_
//#undef _DEBUG_
static void openLogFile(const char*, int);

#define DEF_LOG(level, para) { char logBuf[kLineInfoMaxLenth]; \
int len = sprintf_s(logBuf, kLineInfoMaxLenth, " [%s] [%s: %s] [%s(%d)]\n", (level), __FUNCTION__, (para), __FILE__, __LINE__); \
openLogFile(logBuf, len);}

#define DEF_LOG_INFO(para)    DEF_LOG("INFO", (para))
#define DEF_LOG_WARNING(para) DEF_LOG("WARNING", (para))
#define DEF_LOG_ERROR(para)   DEF_LOG("ERROR", (para))
#ifdef _DEBUG_
#define DEF_LOG_DEBUG(para)   DEF_LOG("DEBUG", (para))
#else
#define DEF_LOG_DEBUG(para)   ;
#endif

#endif //DEFINELOG_H