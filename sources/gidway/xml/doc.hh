// Copyright 2017 (C) Gidway, PL :: gidway.net
#pragma once

#include <cassert>
#include <memory>

namespace gidway {
namespace xml {

template <typename _DOM>
class doc
	: public _DOM
{
public:
	using xml_doc = _DOM;

	virtual ~doc (void) = default;

	doc (void) = default;

}; // class doc

} // namespace xml
} // namespace gidway
