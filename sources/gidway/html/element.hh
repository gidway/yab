// Copyright 2017 (C) Gidway, PL :: gidway.net
#pragma once

#include <xml/node.hh>

namespace gidway {
namespace html {

class Element
	: public ::gidway::xml::Node
{
public:
	using ::gidway::xml::Node;
}; // class Element

} // namespace html

using HTMLElement = html::Element;
} // namespace gidway
