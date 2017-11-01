// Copyright 2017 (C) Gidway, PL :: gidway.net
#pragma once

#include <xml/dom.hh>
#include <html/element.hh>

namespace gidway {
namespace html {

namespace interface {
	class dom
	{
	public:
		virtual void clear (void) = 0;
	}; // class dom
} // namespace interface

class dom
	: public ::gidway::xml::dom<::gidway::html::element>
	, public interface::dom
{
protected:

	virtual ~dom (void) = default;

	dom (void) = default;

public:

	void clear (void) override {
		// TODO
	}

	void _insert_as_content_of(node_type & __node, const char __char) override {
		// TODO
	}

}; // class dom

} // namespace html

using HTMLDom = html::dom;
} // namespace gidway
