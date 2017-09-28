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

	::gidway::Size size (void) const {
		return 0; // TODO
	}

	::gidway::Size layers (void) const {
		return ::gidway::Size::empty(); // TODO
	}

private:
	::gidway::Size _tags_count;
	::gidway::Size _layers_count;
}; // clas Html

} // namespace parsers

using HTMLParser = parsers::Html;
} // namespace gidway
