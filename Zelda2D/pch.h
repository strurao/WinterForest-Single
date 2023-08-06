#pragma once

#include "Types.h"
#include "Defines.h"
#include "Enums.h"
#include "Utils.h"
#include "Values.h"

#include <windows.h>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <functional>
#include <assert.h>
using namespace std;

// C++ 20
#include <format>
#include <filesystem>
namespace fs = std::filesystem;

// �޸� ���� Ȯ�����ش�
#define _CRTDEBG_MAP_ALLOC 
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
// ���� ����ǰ� �ִ� �����̸�, ���°������ ���� ����
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__) 
#endif

#pragma comment(lib, "msimg32.lib")

// Sound
#include <mmsystem.h>
#include <dsound.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dsound.lib")