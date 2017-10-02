// Copyright 2017 (C) Gidway, PL :: gidway.net
#pragma once

#include <cstdlib>
#include <cstdio>

#include <string>
#include <sstream>

namespace gidway {
namespace logs {

constexpr auto end = '\n';

/**
 * Interface for logging
 */
class logger
{
protected:
	virtual ~logger (void) = default;
	logger (void) = default;
public:
	virtual logger & print_header (void) = 0;
	virtual logger & operator << (const std::string &) = 0;	
	virtual logger & operator << (const char) = 0;
	virtual logger & operator << (const int) = 0;
	virtual logger & set_line (unsigned long long) = 0;
	virtual logger & set_color (int) = 0;
	virtual logger & set_stream (FILE*) = 0;
	virtual logger & set_file (const std::string &) = 0;
	virtual logger & set_function (const std::string &) = 0;
	virtual logger & set_symbol (const std::string &) = 0;
}; // class logger

class logs_dummy : public logger
{
protected:
	virtual ~logs_dummy (void) = default;
	logs_dummy (void) = default;
public:
	virtual logger & print_header (void) { return *this; }
	virtual logger & operator << (const std::string &) { return *this; }
	virtual logger & operator << (const char) { return *this; }
	virtual logger & operator << (const int) { return *this; }
	virtual logger & set_line (unsigned long long) { return *this; }
	virtual logger & set_color (int) { return *this; }
	virtual logger & set_stream (FILE*) { return *this; }
	virtual logger & set_file (const std::string &) { return *this; }
	virtual logger & set_function (const std::string &) { return *this; }
	virtual logger & set_symbol (const std::string &) { return *this; }
}; // clas logs_dummy

class logs_base : public logger
{
protected:

	virtual ~logs_base (void) = default;

	logs_base (void) = default;

private:

	int _color {32};
	FILE* _output {stdout};
	unsigned long long _line {0};
	std::string _symbol {"LOG"};
	std::string _file {"none"};
	std::string _function {"none"};

public:

	virtual logger & print_header (void) override {
		fprintf(_output
			, "\e[0;%dm%s::%s:%llu [%s]:\e[0m "
				, _color
				, _symbol.c_str()
				, _file.c_str()
				, _line
				, _function.c_str()
			);
		fflush(_output);
		return *this;
	}

	virtual logger & operator << (const std::string & __msg) override {
		fprintf(_output, "%s", __msg.c_str());
		fflush(_output);
		return *this;
	}
	
	virtual logger & operator << (const char __chr) override {
		fprintf(_output, "%c", __chr);
		fflush(_output);
		return *this;
	}

	virtual logger & operator << (const int __int) override {
		fprintf(_output, "%d", __int);
		fflush(_output);
		return *this;
	}

	virtual logger & set_line (unsigned long long __line) override {
		_line = __line;
		return *this;
	}

	virtual logger & set_color (int __color) override {
		_color = __color;
		return *this;
	}

	virtual logger & set_stream (FILE* _stream) override {
		_output = _stream;
		return *this;
	}

	virtual logger & set_file (const std::string & __str) override {
		_file = __str;
		return *this;
	}

	virtual logger & set_function (const std::string & __str) override {
		_function = __str;
		return *this;
	}

	virtual logger & set_symbol (const std::string & __str) override {
		_symbol = __str;
		return *this;
	}

}; // class logs_base

template <class T_LOGGER = logs_dummy>
class debug : public T_LOGGER
{
public:
	virtual ~debug (void) = default;

	debug (void)
	{
		(*this)
			.set_stream(stderr)
			.set_symbol("DEBUG")
			.set_color(32)
			;
	}

	static T_LOGGER & getInstance (void) {
		static debug _dbg;
		return _dbg;
	}

}; // class debug

template <class T_LOGGER = logs_base>
class error : public T_LOGGER
{
public:
	virtual ~error (void) = default;

	error (void)
	{
		(*this)
			.set_stream(stderr)
			.set_symbol("ERROR")
			.set_color(31)
			;
	}

	static T_LOGGER & getInstance (void) {
		static error _dbg;
		return _dbg;
	}

}; // class debug

template <typename V>
std::string value (const std::string & __name, const V & __value) {
	::std::stringstream ss;
	ss << '[' << __name << '=' << '"' << __value << '"' << ']';
	return ss.str();
}

} // namespace logs
} // namespace gidway

#ifndef NDEBUG
# define LOGGER ::gidway::logs::logs_base
#else
# define LOGGER ::gidway::logs::logs_dummy
#endif

#define dbgD ::gidway::logs::debug<LOGGER>::getInstance() \
	.set_line(__LINE__) \
	.set_file(__FILE__) \
	.set_function(__FUNCTION__) \
	.print_header()

#define debuglog dbgD // historical reasons

#define debugtrace dbgD << "TRACE" << ::gidway::logs::end;

#define dbgE ::gidway::logs::error<logs_base>::getInstance() \
	.set_line(__LINE__) \
	.set_file(__FILE__) \
	.set_function(__FUNCTION__) \
	.print_header()

