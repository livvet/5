#include <UnitTest++/UnitTest++.h>
#include <../GenRandomSequence/GenRandomSequence.cpp>

SUITE(KeyTest)
{
	vector<int> reg1 = {1, 1, 0, 0, 1};
	TEST(CorrectData) {
		GenRandomSequence object(reg1);
		CHECK(true);
	}
	vector<int> reg2 = {};
	TEST(EmptyString) {
		CHECK_THROW(GenRandomSequence object(reg2), GenRandom_error);
	}
	vector<int> reg3 = {1, 2, 1, 0, 1};
	TEST(InvalidCharacter) {
		CHECK_THROW(GenRandomSequence object(reg3), GenRandom_error);
	}
	vector<int> reg4 = {0, 0, 0, 0, 0};
	TEST(ZeroCase) {
		CHECK_THROW(GenRandomSequence object(reg4), GenRandom_error);
	}
	vector<int> reg5 = {1, 0};
	TEST(CaseIsShort) {
		CHECK_THROW(GenRandomSequence object(reg5), GenRandom_error);
	}
	
}

vector<int> reg = {1, 1, 0, 0, 1};
struct GenRandomSequence_fixture {
	GenRandomSequence * object;
	GenRandomSequence_fixture() {
		object = new GenRandomSequence(reg);
	}
	~GenRandomSequence_fixture() {
		delete object;
	}
};

SUITE(GenerateTest) {
	TEST_FIXTURE(GenRandomSequence_fixture, CorrectData){
		object->generate(5);
		CHECK(true);
	}
	TEST_FIXTURE(GenRandomSequence_fixture, ZeroLength){
		CHECK_THROW(object->generate(0),GenRandom_error);
	}
	TEST_FIXTURE(GenRandomSequence_fixture, ThereIsLetter){
		CHECK_THROW(object->generate(-5),GenRandom_error);
	}
}

int main(int argc, char **argv) {
	return UnitTest::RunAllTests();
}