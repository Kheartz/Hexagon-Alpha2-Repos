print("You're in Carbon, Where Art Thou.lua")

CWAT = Quest_Deliver:new()

CWAT:setStartNPC(em:getNPC("Delphine"))
CWAT:setItem(em:getItem("Carbon"))
CWAT:setEndNPC(CWAT:getStartNPC())

print(CWAT:getItem():getName())

CWAT:setName("Carbon, Where Art Thou?")

CWAT:setActiveConvo([[
Greetings! I'm looking for a certain magical power that the Alchemists have been searching of for years! Would you like to help me?
]])

CWAT:getStartNPC():setConversation(CWAT:getActiveConvo())
CWAT:setActivecyConvo([[Brilliant! I've heard it's somewhere in the sewers. Return to me the magical element and I'll reward you nicely.
]])

CWAT:setActivecnConvo([[It's okay, my dear fellow. I'll see you later. Come back if you want to help!
]])

CWAT:setStartedConvo([[Did you pick up the magical element that should be somewhere in the Sewers?
]])

CWAT:setStartedcnConvo([[Keep looking!]])

CWAT:setStartedcyfConvo([[Try again!]])

CWAT:setStartedcytConvo([[Brilliant! You've amazed me. I'll make sure the mayor knows of your good deed. In the mean time, I'll break you off a piece.

]])

CWAT:setDoneConvo([[You're a great help!]])

CWAT:pushItemsGive("Carbon")
qm:addQuest(CWAT)






--[[ACTIVE:Greetings! I'm looking for a certain magical power that the Alchemists have been searching of for years! Would you like to help me?
ACTIVECY:Brilliant! I've heard it's somewhere in the sewers. Return to me the magical element and I'll reward you nicely.
ACTIVECN:It's okay, my dear fellow. I'll see you later. Come back if you want to help!
STARTED:Did you pick up the magical element that should be somewhere in the Sewers?
STARTEDCN:Keep looking!
STARTEDCYF:Try again!
STARTEDCYT:Brilliant! You've amazed me. I'll make sure the mayor knows of your good deed. In the mean time, I'll break you off a piece.
DONE:You're a great help!

]]--