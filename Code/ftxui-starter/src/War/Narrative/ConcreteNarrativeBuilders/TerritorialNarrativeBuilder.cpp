#include "TerritorialNarrativeBuilder.h"

//TODO: Be a bit smarter about picking countries from the vectors
//NOTE: countriesA are assumed to be the attackers (the side that initiates the war by making the first move)

void TerritorialNarrativeBuilder::setDispute(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.dispute = NarrativeBuilder::pickRandom({
        countriesA[0] + " is unhappy that their land was annexed by " + countriesB[0] + " hundreds of years ago, now they want it back.",
        "A great river divides the lands of " + countriesA[0] + " and " + countriesB[0] + " , who have been enemies for years. Following the assassination of " + countriesB[0] + "'s president, they have decided to attack their neighbour."
    });
}

void TerritorialNarrativeBuilder::setHostilities(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.hostilities = NarrativeBuilder::pickRandom({
        "Small fights have broken out over secluded pieces of land",
        "Farmland has been the first target of " + countriesA[0] + ". Hundreds of farms and their workers have perished due to the onslaught."
    });
}

void TerritorialNarrativeBuilder::setPostWar(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.postWar = NarrativeBuilder::pickRandom({
        countriesA[0] + " is still hostile towards " + countriesB[0] + " however the conflict has settled down enough that the war is nearing its conclusion.",
    });
}

void TerritorialNarrativeBuilder::setDisputeSettled(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.disputeSettled = NarrativeBuilder::pickRandom({
        "The territorial dispute has finally settled, though " + countriesB[0] + " and " + countriesB[1] + " are reluctant to accept the resolution.",
        "After a great many casualties suffered, the war has finally been resolved and new country borders have been established."
    });
}