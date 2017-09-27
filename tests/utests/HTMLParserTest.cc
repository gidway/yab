// Copyright 2017 (C) Gidway, PL :: gidway.net

#include <gtest/gtest.h>

#include <parsers/html.hh>

class HTMLParserTest : public ::testing::Test {
};

TEST_F(HTMLParserTest, by_constructor) {
	constexpr auto & HTML_CONTENT = "<html></html>";
	gidway::parsers::Html html (HTML_CONTENT);
}

TEST_F(HTMLParserTest, check_size) {
	constexpr auto EXPECTED_ITEM_COUNTS = 4; // html, head, meta, body
	constexpr auto EXPECTED_LAYERS_COUNTS = 3; // html(1) >> head(2) >> meta(3), html(1) >> body(2) => 3(max)
	constexpr auto & HTML_CONTENT = "<html><head><meta charset=\"utf-8\" /></head><body></body></html>";

	gidway::parsers::Html html (HTML_CONTENT);

	EXPECT_EQ(html.size(), EXPECTED_ITEM_COUNTS);
	EXPECT_EQ(html.layers(), EXPECTED_LAYERS_COUNTS);
}
