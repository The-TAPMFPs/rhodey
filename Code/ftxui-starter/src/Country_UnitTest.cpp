#include <gtest/gtest.h>

#include "Country/Country.h"
#include "Country/BattleStrategy/Intel.h"
#include "logger.h"

struct CountryTest : testing::Test {
    Country* country;
    CountryTest() {
        country = new Country("TestCountry");
    }
    ~CountryTest() {
        delete country;
    }
};

TEST_F(CountryTest, SpyTest) {
    Logger::log("NaN");

    // tests that an country recieves updates on a country it is spying on
    Alliance* myTeam = new Alliance("good Team", 0);
    Alliance* enemyTeam = new Alliance("Bad Team", 0);
    myTeam->setEnemyAlliance(enemyTeam);
    enemyTeam->setEnemyAlliance(myTeam);

    myTeam->add(country);
    Country* enemyCountry = new Country("BadGuys");
    enemyTeam->add(enemyCountry);


    country->setStrategy(new Intel()); // should be spyign on enemy country
    country->strategy->doStrategy(country);
    std::string wantedMessage = country->getName() + " is now spying on: " +
	enemyCountry->getName() + "\n";
    EXPECT_EQ(Logger::getMsg(), wantedMessage);


    enemyCountry->alertSpyCountries();
    EXPECT_EQ(Logger::getMsg(), country->getName() + " is now spying on: " + enemyCountry->getName() + "\n");
    double countryIntel = (*country->getCountriesBeingSpiedOn())[0].second;
    EXPECT_EQ(countryIntel, 0);
}
