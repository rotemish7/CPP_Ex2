//
// Created by rotem levy on 16/04/2020.
//

#include "doctest.h"
#include "FamilyTree.hpp"
#include <iostream>

using namespace std;

family::Tree A("Adam");
family::Tree E("Eve");

TEST_CASE("Family tree creator")
{
    CHECK_NOTHROW(A.addFather("Adam", "moshe"));
    CHECK_NOTHROW(A.addMother("Adam", "none"));
    CHECK_NOTHROW(A.addFather("moshe", "Adam"));
    CHECK_NOTHROW(A.addMother("moshe", "yoch"));
    CHECK_NOTHROW(A.addFather("zipora", "daddy"));
    CHECK_NOTHROW(A.addMother("zipora", "yoch"));
    CHECK_NOTHROW(A.addMother("miki", "tal"));


    CHECK_THROWS(A.addFather("Adam", "ygal"));
    CHECK_THROWS(A.addMother("moshe", "yoch"));
    CHECK_THROWS(A.addFather("micha", "sasa"));
    CHECK_THROWS(A.addMother("moshe", ""));
    CHECK_THROWS(A.addMother("", "lally"));

    CHECK_NOTHROW(E.addFather("Eve","jesus"));
    CHECK_NOTHROW(E.addMother("Eve","maria"));
    CHECK_NOTHROW(E.addMother("mario","sarah"));
    CHECK_NOTHROW(E.addFather("shani","David"));
    CHECK_NOTHROW(E.addFather("mario","trump"));
    CHECK_NOTHROW(E.addMother("shani","ani"));
    CHECK_THROWS(E.addFather("Eve","Eve"));
    CHECK_THROWS(E.addFather("Eve","maria"));
    CHECK_THROWS(E.addFather("trump",""));
    CHECK_THROWS(E.addMother("","none"));
    CHECK_NOTHROW(E.addFather("alon","oren"));
}

family::Tree B("Aharon");
TEST_CASE("relation test")
{
    CHECK_NOTHROW(A.relation("ygal"));
    CHECK_NOTHROW(A.relation("yoch"));
    CHECK_NOTHROW(A.relation("none"));
    CHECK(A.relation("none")==string("mother"));
    CHECK(A.relation("tali")==string("grandmother"));
    CHECK(A.relation("ibgeni")==string("grandmother"));
    CHECK(A.relation("gal")==string("great-grandmother"));
    CHECK_FALSE(A.relation("ester")==string("great-grandfather"));
    CHECK_FALSE(A.relation("elroy")==string("mother"));

    CHECK_THROWS(A.relation(""));
    CHECK_THROWS(A.relation("father"));
    CHECK_THROWS(A.relation("faruik"));
    CHECK_THROWS(A.relation("gree"));
    CHECK_NOTHROW(B.addFather("rew","rw"));
    CHECK_NOTHROW(B.addMother("rw","rw"));
    CHECK_NOTHROW(B.addMother("re","fdgbe"));
    CHECK_NOTHROW(B.addFather("erhge","rg"));
    CHECK_NOTHROW(B.addFather("reg","rwg"));
    CHECK_NOTHROW(B.addMother("wet","wg3"));
    CHECK(B.relation("wrg")==string("grandmother"));
    CHECK(B.relation("wegt")==string("grandfather"));
    CHECK(B.relation("wt")==string("mother"));
    CHECK_THROWS(B.relation("wet"));
    CHECK_THROWS(B.relation(""));
    CHECK(B.relation("5h")==string("grandfather"));
}

family::Tree F("ger");
family::Tree C("tnjry");

TEST_CASE("find test")
{
    CHECK_NOTHROW(F.addFather("ger", "ver"));
    CHECK_NOTHROW(F.addFather("rgr", "hrtju"));
    CHECK_NOTHROW(F.addMother("h5y6", "degg"));

    CHECK(A.find("father")==string("het"));
    CHECK(A.find("mother")==string("nhjet"));
    CHECK(A.find("grandfather")==string("erthy"));
    CHECK(A.find("grandmother")==string("t53r"));
    CHECK(A.find("father")==string("rtj"));
    CHECK_THROWS(B.find("mother"));
    CHECK(B.find("grandmother")==string("mykrt"));
    CHECK_NOTHROW(C.addFather("bed","dfb"));
    CHECK_NOTHROW(C.addMother("rewg","gw"));
    CHECK_NOTHROW(C.addMother("ge","vs"));
    CHECK_NOTHROW(C.addFather("ge","bd"));
    CHECK_NOTHROW(C.addFather("ge","bd"));
    CHECK_NOTHROW(C.addMother("vsg","vgs"));
    CHECK(C.find("father")==string("bd"));
    CHECK_THROWS(C.find("great-great-grandmother"));
    CHECK_THROWS(C.find("great-great-grandfather"));
    CHECK_THROWS(C.find("great-great-great-grandmother"));
    CHECK_THROWS(C.find("great-great-great-grandfather"));
    CHECK(C.find("grandfather")==string("fdsh"));
    CHECK(C.find("grandmother")==string("gs"));

}
family::Tree x3("hrty");
family::Tree T4("hr");
TEST_CASE("remove test")
{

    CHECK_NOTHROW(x3.addFather("rg", "magrk"));
    CHECK_NOTHROW(x3.addMother("fs", "ghdf"));
    CHECK_NOTHROW(x3.addFather("er", "morwghe"));
    CHECK_NOTHROW(x3.addMother("gerfg", "ghs"));
    CHECK_NOTHROW(x3.addFather("egswma", "gwgws"));
    CHECK_NOTHROW(x3.addMother("jkuy", "ky"));
    CHECK_NOTHROW(x3.addMother("hr", "ger"));

    CHECK_THROWS(x3.remove("hr"));
    CHECK_THROWS(x3.remove("ge"));
    CHECK_THROWS(x3.remove("gej"));
    CHECK_THROWS(x3.remove(""));
    CHECK_THROWS(x3.remove("jtu"));

    CHECK_NOTHROW(x3.remove("tyjk"));
    CHECK_NOTHROW(x3.remove("trjy"));
    CHECK_NOTHROW(x3.remove("tyj"));
    CHECK_NOTHROW(x3.remove("rhjr"));
    CHECK_NOTHROW(x3.remove("ykr"));
    CHECK_NOTHROW(x3.remove("kt"));
    CHECK_NOTHROW(x3.remove("hjrtu"));

    CHECK_NOTHROW(T4.addFather("ofir", "nissan"));
    CHECK_NOTHROW(T4.addMother("ofir", "lital"));
    CHECK_NOTHROW(T4.addMother("alma", "lital"));
    CHECK_NOTHROW(T4.addFather("ariel", "nissan"));
    CHECK_NOTHROW(T4.addFather("michaela", "Nissan"));
    CHECK_NOTHROW(T4.addMother("ariel", "lital"));
    CHECK_THROWS(T4.remove(""));
    CHECK_THROWS(T4.remove("ofir"));
    CHECK_THROWS(T4.remove("grandfather"));
    CHECK_NOTHROW(T4.remove("ariel"));
    CHECK_THROWS(T4.remove("nissan"));
    CHECK_NOTHROW(T4.remove("michaela"));
    CHECK_THROWS(T4.remove("lital"));

}