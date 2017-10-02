// Copyright 2017 (C) Gidway, PL :: gidway.net

#pragma once

#include <utils/size.hh>

#include <parsers/parser.hh>

#include <html/doc.hh>

namespace gidway {
namespace parsers {

class Html
	: public gidway::parsers::Parser
{
public:
	using gidway::parsers::Parser::Parser;

	virtual ~Html() {}

	/**
	 * Load HTML content
	 */
	explicit Html (const char*);

	::gidway::Size countTags (void) const {
		return _tags_count;
	}

	::gidway::Size countChars (void) const {
		return _chars_count;
	}

private:
	::gidway::Size _tags_count;
	::gidway::Size _chars_count;

	::gidway::html::doc _dom;

}; // clas Html

} // namespace parsers

using HTMLParser = parsers::Html;
} // namespace gidway
