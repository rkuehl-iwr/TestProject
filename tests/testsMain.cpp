#define CATCH_CONFIG_MAIN
#include <catch.hpp>
//no other purpose than implementing CATCH_CONFIG_MAIN
//working-directory of the test should be the parent-path of the GigaMesh-Repository

SCENARIO("simple not Failing test")
{
	REQUIRE(1==1);
}

SCENARIO("simple succeding test")
{
	REQUIRE(0==0);
}
