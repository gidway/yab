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
 * Working as job-machine, where jobs are switched by input data (chars)
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
	 * Machine of jobs
	 */
	class job {
	public:

		job (doc & __doc)
			: _doc(__doc)
		{
		}

		virtual void exec (const char) = 0;

	protected:

		virtual ~job (void) = default;

		doc & _doc;
		job * _parent_job {nullptr};

	}; // class job

public:
	virtual ~doc (void) = default;

	doc (void)
		: _current_job(*this)
	{
	}

	void clear (void) override {
		// TODO
		dom::clear();
	}

	doc & operator << (const char __c) {
		_exec_job_for_char(__c);
		return *this;
	}

	doc & operator << (const std::string & __str) {
		for (const auto c : __str) {
			(void) (*this).operator<<(static_cast<const char>(c));
		}
		return *this;
	}

	node_type & current_node (void) {
		return *_current_node;
	}

protected:

	struct current_job final
	{
		~current_job (void) = default;

		class init;
		class finished;
		class tag_begin;
		class tag_end;
		class tag_set_name;
		class tag_set_attribute_name;
		class tag_set_attribute_value;

		class init : public job { public: using job::job;
			void exec (const char) override;
		}; // class init

		class tag_begin : public job { public: using job::job;
			void exec (const char) override {}
		}; // class tag_begin

		class tag_end : public job { public: using job::job;
			void exec (const char) override {}
		}; // class tag_end

		::std::shared_ptr<job> _job;

		current_job (doc & __doc)
			: _job(::std::make_shared<init>(__doc))
		{
		}

		void exec (const char __c) {
			_job->exec(__c);
		}

	} _current_job; // struct current_job

	/**
	 * Take a decision about object job on char
	 * On default action, if we not supoort any job for redirected char,
	 * the char will be inserted into some abject as content.
	 */
	void _exec_job_for_char (const char);

private:

	::std::shared_ptr<node_type> _current_node;

}; // class doc

} // namespace html

using HTMLDoc = html::doc;
} // namespace gidway
