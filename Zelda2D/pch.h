#pragma once

#include "Types.h"
#include "Defines.h"
#include "Enums.h"
#include "Utils.h"
// #include "Values.h"

#include <windows.h>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

#include <format>

// �޸� ���� Ȯ�����ش�
#define _CRTDEBG_MAP_ALLOC 
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
// ���� ����ǰ� �ִ� �����̸�, ���°������ ���� ����
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__) 
#endif