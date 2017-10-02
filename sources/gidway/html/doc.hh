// Copyright 2017 (C) Gidway, PL :: gidway.net
#pragma once

#include <string>

#include <xml/doc.hh>
#include <html/element.hh>

namespace gidway {

namespace html {

class doc
	: public ::gidway::xml::doc<::gidway::html::element>
{
public:
	virtual ~doc (void) = default;
	doc (void) = default;

	void clear (void) {
		// TODO
	}

	doc & operator << (const char __c) {
		return *this;
	}

	doc & operator << (const std::string & __str) {
		return *this;
	}

}; // class doc

} // namespace html

using HTMLDoc = html::doc;
} // namespace gidway
