// Copyright 2017 (C) Gidway, PL :: gidway.net

#pragma once

#include <utils/size.hh>

#include <parsers/parser.hh>

#include <html/doc.hh>

namespace gidway {
namespace parsers {

class Html
	: public ::gidway::parsers::Parser
	, public ::gidway::html::doc
{
public:
	using gidway::parsers::Parser::Parser;

	virtual ~Html() {}

	/**
	 * Load HTML content
	 */
	explicit Html (const char*);

}; // clas Html

} // namespace parsers

using HTMLParser = parsers::Html;
} // namespace gidway
