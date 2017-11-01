// Copyright 2017 (C) Gidway, PL :: gidway.net
#pragma once

#include <memory>
#include <string>

#include <xml/doc.hh>
#include <html/dom.hh>

namespace gidway {
namespace html {

/**
 * This class generate elements of DOM
 * Working as state-machine, where states are switched by input data (chars)
 * States, like:
 * - open creation of tag
 * - closed created tag
 * - insert data to: attribute name, attribute value, text node...
 *   ect.
 */
class doc
	: public ::gidway::xml::doc<::gidway::html::dom>
{
	using xml_base = ::gidway::xml::doc<::gidway::html::dom>;

	/**
	 * Machine of states / jobs
	 */
	class state {
	public:
		state (void) = default;
		state (const char) {} // TODO
	protected:
		virtual ~state (void) = default;
	};

public:
	virtual ~doc (void) = default;
	doc (void) = default;

	void clear (void) override {
		// TODO
		dom::clear();
	}

	doc & operator << (const char __c) {
		_switch_state_by_char(__c);
		return *this;
	}

	doc & operator << (const std::string & __str) {
		for (const auto c : __str) {
			(void) doc::operator<<(static_cast<const char>(c));
		}
		return *this;
	}

protected:

	struct current_state final
	{
		~current_state (void) = default;

		class init;
		class finished;
		class tag_begin;
		class tag_end;
		class tag_set_name;
		class tag_set_attribute_name;
		class tag_set_attribute_value;

		class init : public state {};
		class finished : public state {};
		class tag_set_name: public state {};
		class tag_set_attribute_name : public state {};
		class tag_set_attribute_value : public state {};

		class tag_begin : public state {
		public:
			using state::state;
		}; // class tag_begin

		class tag_end : public state {
		public:
			using state::state;
		}; // class tag_end

		::std::shared_ptr<state> _state;

		current_state (void)
			: _state(::std::make_shared<init>())
		{
		}

	}; // struct current_state

	/**
	 * Take a decision about object state on char
	 * On default action, if we not supoort any job for redirected char,
	 * the char will be inserted into some abject as content.
	 */
	void _switch_state_by_char (const char);

private:

	current_state _current_state;

	::std::shared_ptr<node_type> _current_node;

}; // class doc

} // namespace html

using HTMLDoc = html::doc;
} // namespace gidway
