//
//  util.h
//  MiniProjecto2 AED
//
//  Created by Nilson Lopes on 23/06/14.
//  Copyright (c) 2014 Nilson Lopes. All rights reserved.
//

#ifndef _libutil_h
#define _libutil_h
//Apple OS X
#ifdef __APPLE__
#define clean_buffer fpurge(stdin)
#define clear_screen "clear"
//Linux
#elif defined __linux__
#include <stdio_ext.h>
#define clean_buffer __fpurge(stdin)
#define clear_screen "clear"
//Windows
#elif defined _WIN32_
#define clean_buffer fflush(stdin)
#define clear_screen "cls"
#endif
void flush_buffer(void);

void pause(void);
#endif
