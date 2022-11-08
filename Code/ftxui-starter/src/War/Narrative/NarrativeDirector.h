#pragma once

#include "ConcreteNarrativeBuilders/EconomicNarrativeBuilder.h"
#include "ConcreteNarrativeBuilders/TerritorialNarrativeBuilder.h"
#include "ConcreteNarrativeBuilders/RevengeNarrativeBuilder.h"
#include "ConcreteNarrativeBuilders/ReligiousNarrativeBuilder.h"
#include "ConcreteNarrativeBuilders/PoliticalNarrativeBuilder.h"
#include "../../Country/Alliance.h"

class NarrativeDirector
{
    private:
        Alliance *teamA, *teamB;
        void executeStandardMake(NarrativeBuilder* builder);

    public:
        NarrativeDirector(Alliance* teamA, Alliance* teamB);
        Narrative makeEconomicNarrative();
        Narrative makeTerritorialNarrative();
        Narrative makeRevengeNarrative();
        Narrative makeReligiouslNarrative();
        Narrative makePoliticalNarrative();
};