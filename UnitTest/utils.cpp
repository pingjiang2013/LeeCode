#include "pch.h"
#include "utils.h"
#include <stdarg.h>
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void impPrintInUnitTest(const char* fmt, va_list va)
{
	char buf[MAX_LENGTH];
	vsnprintf(buf, MAX_LENGTH, fmt, va);
	Logger::WriteMessage(buf);
}

void printInUnitTest(const char* fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	impPrintInUnitTest(fmt, va);
	va_end(va);
}

