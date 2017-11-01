// Copyright 2017 (C) Gidway, PL :: gidway.net

#include <parsers/html.hh>

#include <algorithms/streams/chars.hh>

#include <logs/debug.hh>

namespace gidway {
namespace parsers {

Html::Html (const char* __content) {
	const ::gidway::algorithms::streams::chars rawContent(__content);
	auto & it = rawContent.begin();

	doc::clear();

	while (not it.end()) {
		(*this).doc::operator<<(*it);
		++it;
	}
}

} // namespace parsers
} // namespace gidway
