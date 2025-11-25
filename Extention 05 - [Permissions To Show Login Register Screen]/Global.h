#pragma once
#include"ClsUser.h"
using namespace std;

ClsUser CurrentUser = ClsUser::Find("", "");

short Counter = 0;

enum enStatus { Locked = 1, UnLocked = 2 };

enStatus Status = UnLocked;