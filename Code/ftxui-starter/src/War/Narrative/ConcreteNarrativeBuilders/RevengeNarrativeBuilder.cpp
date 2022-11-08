#include "RevengeNarrativeBuilder.h"

void RevengeNarrativeBuilder::setDispute(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.dispute = NarrativeBuilder::pickRandom({
        countriesA[0] + " is disgrunted that their country was exploited for hundreds of years by " + countriesB[0],
        "They elect to seek 'Reperations' delivering the same exploits on those that wronged them."
    });
}

void RevengeNarrativeBuilder::setHostilities(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.hostilities = NarrativeBuilder::pickRandom({
        "Issues begin to arise, tensions are at an all time high",
        countriesA[0] + " has begun to show its hand, they begin to push the bounderies of peace in the name of 'Payback'.",
        countriesB[0] + " begin to prepare to fight back."
    });
}

void RevengeNarrativeBuilder::setPostWar(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.postWar = NarrativeBuilder::pickRandom({
        "Tensions are still there however " + countriesA[0] + " and " + countriesB[0] + " are tired of fighting, there people want to go home."
     });
}

void RevengeNarrativeBuilder::setDisputeSettled(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.disputeSettled = NarrativeBuilder::pickRandom({
        "The war is over, the need for revenge has blown away like sand in the desert, " + countriesA[0] + " exacted its revenge...",
        "but at what cost."
        "If wars can be started by lies they can be stopped by truth ~ Julian Assange" 
    });
}

void RevengeNarrativeBuilder::setConflict(std::vector<std::string> countriesA, std::vector<std::string> countriesB) {
    product.conflict = NarrativeBuilder::pickRandom({
        countriesA[0] + " know what they are doing is wrong, but they thing this THIS time revenge against " + countriesB[0] + " will leave them satisfied."
    });
}