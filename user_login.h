#pragma once

#include "user_struct.h"
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <Windows.h>
#include "user_membership.h"
#pragma warning(disable:4996)

user *login_member(user *user_temp);
user *login_nonmember(user *user_temp);
