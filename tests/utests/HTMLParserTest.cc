// Copyright 2017 (C) Gidway, PL :: gidway.net

#include <gtest/gtest.h>

#include <string>

#include <parsers/html.hh>

class HTMLParserTest : public ::testing::Test {
};

TEST_F(HTMLParserTest, by_constructor) {
	constexpr auto & HTML_CONTENT = "<html></html>";
	gidway::parsers::Html html (HTML_CONTENT);
}

TEST_F(HTMLParserTest, check_size) {
	constexpr auto EXPECTED_ITEM_COUNTS = 4; // html, head, meta, body
	const std::string & testedHtmlContent {"<html><head><meta charset=\"utf-8\" /></head><body></body></html>"};

	gidway::parsers::Html html (testedHtmlContent.c_str());

	// TODO impl some method for this test case
}
