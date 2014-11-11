
print("You're in testquest.lua")

testquest = Quest_GoTo_NPC:new()

testquest:setStartNPC(em:getNPC("Bunny1"))
testquest:setTargetNPC(em:getNPC("Bunny2"))
testquest:setEndNPC(testquest:getStartNPC())


testquest:setName("TEST QUEST")

testquest:setActiveConvo([[
Welcome to the test quest. 
My name is Mr. Bunny McFuggets.
You will have your shit pushed in. 
Are you ready? :D]])

testquest:getStartNPC():setConversation(testquest:getActiveConvo())
testquest:setActivecyConvo([[
I guess you like it like that. 
Here we go. I need you to talk to my twin.
Come back and I will give you something that you will never forget. ;)
]])

testquest:setActivecnConvo([[
You're a pussy. Come back when you're a real hunk.
]])

testquest:setStartedConvo([[
You need to talk to my twin. Or else I will push your shit in somewhere else.
Did you take care of that for me?
]])

testquest:setStartedcnConvo([[
Look here you little piece of shit. Come back when you take care of business.
Or else....Shit will happen.
]])

testquest:setStartedcyfConvo([[
You lying piece of shit. Lie to me one more time and I will have your heads.
]])

testquest:setStartedcytConvo([[
Wow. I didn't think you were hunk enough to do this quest. 
]])

testquest:setDoneConvo([[
Good shit son. 	Here is something for your troubles.
]])

testquest:pushItemsGive("Potion")
testquest:pushItemsGive("Carbon")
testquest:pushItemsGive("Chlorine")
qm:addQuest(testquest)