#include "Entity.hpp"

inline std::ostream& White(std::ostream& Stream)
{
	HANDLE LibraryHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(LibraryHandler, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return Stream;
}

inline std::ostream& Red(std::ostream& Stream)
{
	HANDLE LibraryHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(LibraryHandler, FOREGROUND_RED);
	return Stream;
}

inline std::ostream& Green(std::ostream& Stream)
{
	HANDLE LibraryHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(LibraryHandler, FOREGROUND_GREEN);
	return Stream;
}

inline std::ostream& Yellow(std::ostream& Stream)
{
	HANDLE LibraryHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(LibraryHandler, FOREGROUND_GREEN | FOREGROUND_RED);
	return Stream;
}

inline std::ostream& Purple(std::ostream& Stream)
{
	HANDLE LibraryHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(LibraryHandler, FOREGROUND_RED | FOREGROUND_BLUE);
	return Stream;
}

inline std::ostream& Cyan(std::ostream& Stream)
{
	CONSOLE_SCREEN_BUFFER_INFOEX TransformColor;
	TransformColor.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

	HANDLE ConsoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfoEx(ConsoleHandler, &TransformColor);

	TransformColor.ColorTable[3] = RGB(13, 114, 168);

	SetConsoleScreenBufferInfoEx(ConsoleHandler, &TransformColor);
	SetConsoleTextAttribute(ConsoleHandler, 3);
	return Stream;
}
struct ColorHandler
{
	ColorHandler(unsigned long AttributeSet) :
		Color(AttributeSet) { };
	unsigned long Color;
};

template <class Elements, class SetColorAttribute>
std::basic_ostream<Elements, SetColorAttribute>& operator<<(std::basic_ostream<Elements, SetColorAttribute>& Stream, ColorHandler& SetColor)
{
	HANDLE LibraryHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(LibraryHandler, SetColor.Color);
	return Stream;
}

namespace Console
{
	void FormatCyan(const char* Input)
	{
		std::cout << White << "[" << Cyan << "x" << White << "] " << White << Input;
	}

	void FormatRed(const char* Input)
	{
		std::cout << White << "[" << Red << "x" << White << "] " << White << Input;
	}

	void FormatGreen(const char* Input)
	{
		std::cout << White << "[" << Green << "x" << White << "] " << White << Input;
	}

	void FormatYellow(const char* Input)
	{
		std::cout << White << "[" << Yellow << "x" << White << "] " << White << Input;
	}

	void FormatPurple(const char* Input)
	{
		std::cout << White << "[" << Purple << "x" << White << "] " << White << Input;
	}
}