// Copyright 2017 (C) Gidway, PL :: gidway.net
#include <gidway/html/doc.hh>
namespace gidway {
namespace html {

void doc::_exec_job_for_char (const char __c) {
	switch (__c) {
		case '<':
		case '>':
		default:
			xml_base::_insert_as_content_of((*_current_node), __c);
			break;
	} // switch (__c)
}

} // namespace html
} // namespace gidway
