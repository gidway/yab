// Copyright 2017 (C) Gidway, PL :: gidway.net

#include <parsers/html.hh>

#include <algorithms/streams/chars.hh>

#include <logs/debug.hh>

namespace gidway {
namespace parsers {

Html::Html (const char* __content) {
	const ::gidway::algorithms::streams::chars rawContent(__content);
	auto & it = rawContent.begin();

	_dom.clear();

	while (not it.end()) {
		++_chars_count;
		//
		debuglog << "inside loop while / after ++ it = " << (*it) << logs::end;
		_dom << (*it);
		//
		++it;
	}
}

} // namespace parsers
} // namespace gidway
