#define CATCH_CONFIG_MAIN
#include <catch.hpp>
//no other purpose than implementing CATCH_CONFIG_MAIN
//working-directory of the test should be the parent-path of the GigaMesh-Repository

SCENARIO("simple Failing test")
{
	REQUIRE(1==0);
}

SCENARIO("simple succeding test")
{
	REQUIRE(0==0);
}
