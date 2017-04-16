#ifndef DEFINELOG_H
#define DEFINELOG_H

#include <stdio.h>
#include <time.h>

#define _DEBUG_
//#undef _DEBUG_
static const char* getCurrentTmie(void);

#define DEF_LOG(level, para) printf("%s [%s] [%s: %s] [%s(%d)]\n", getCurrentTmie(), (level), __FUNCTION__, (para), __FILE__, __LINE__);

#define DEF_LOG_INFO(para)    DEF_LOG("INFO", (para))
#define DEF_LOG_WARNING(para) DEF_LOG("WARNING", (para))
#define DEF_LOG_ERROR(para)   DEF_LOG("ERROR", (para))
#ifdef _DEBUG_
#define DEF_LOG_DEBUG(para)   DEF_LOG("DEBUG", (para))
#else
#define DEF_LOG_DEBUG(para)   ;
#endif

#endif //DEFINELOG_H