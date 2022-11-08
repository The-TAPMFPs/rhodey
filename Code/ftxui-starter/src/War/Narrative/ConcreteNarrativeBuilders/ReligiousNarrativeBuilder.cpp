#include "ReligiousNarrativeBuilder.h"

void ReligiousNarrativeBuilder::setDispute(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.dispute = NarrativeBuilder::pickRandom({
        "The Pastafarian state of " + countriesA[0] + " begins proclaiming how the flying spaghetti monster will come soon." 
        + countriesB[0] + " the homeplace of Rastafarinism begins arguing with, " + countriesA[0] + ", claiming that even for them the idea is far fetched.",
    });
}

void ReligiousNarrativeBuilder::setHostilities(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.hostilities = NarrativeBuilder::pickRandom({
        "The two religious groups begin to clash " + countriesA[0] + " stands by what they believe in and " + countriesB[0] + " stays true to their beliefs",
        "These clashes begin to escalate and what were once just mere arguments begin turning into fights, military action is looking more and more possible."
    });
}

void ReligiousNarrativeBuilder::setPostWar(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.postWar = NarrativeBuilder::pickRandom({
        "The immediate fighting has ceased, there are still avid believers from both " + countriesA[0] + " and " + countriesB[0] + " who insist fighting is still necessary",
        "however most have no more belief in the effort." 
    });
}

void ReligiousNarrativeBuilder::setDisputeSettled(std::vector<std::string> countriesA, std::vector<std::string> countriesB)
{
    product.disputeSettled = NarrativeBuilder::pickRandom({
        "Fighting has permentally stopped " + countriesA[0] + " believes that the war scared the flying spaghetti monster away and " + countriesB[0] + " can't remember why they fighting.",
        "Religious wars are basically people killing each other over who has the better imaginary friend ~ Napolean Dynamite"
    });
}

void ReligiousNarrativeBuilder::setConflict(std::vector<std::string> countriesA, std::vector<std::string> countriesB) {
    product.conflict = NarrativeBuilder::pickRandom({
        "The poeple of  " + countriesA[0] + " believe that their holy leader has is using them as toys against the enemy " + countriesB[0] + ". Toys that are being used to kill each other.",
    });
}