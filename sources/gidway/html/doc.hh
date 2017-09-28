// Copyright 2017 (C) Gidway, PL :: gidway.net
#pragma once

#include <xml/doc.hh>

namespace gidway {
	class HTMLElement;

namespace html {

class Doc
	: public ::gidway::xml::doc<::gidway::HTMLElement>
{
}; // class Doc

} // namespace html

using HTMLDoc = html::Doc;
} // namespace gidway
