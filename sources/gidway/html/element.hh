// Copyright 2017 (C) Gidway, PL :: gidway.net
#pragma once

#include <xml/node.hh>

namespace gidway {
namespace html {

class element
	: public ::gidway::xml::node
{
public:
	using ::gidway::xml::node::node;
}; // class element

} // namespace html

using HTMLElement = html::element;
} // namespace gidway
