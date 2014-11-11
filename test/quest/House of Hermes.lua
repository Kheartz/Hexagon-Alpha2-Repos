
print("You're in House of Hermes.lua")

houseofhermes = Quest_GoTo_Area:new()

houseofhermes:setStartNPC(em:getNPC("Baurn"))
houseofhermes:setTargetArea(2528, 1120, 1280, 1280)
houseofhermes:setEndNPC(houseofhermes:getStartNPC())


houseofhermes:setName("House of Hermes")

houseofhermes:setActiveConvo([[
Elliot, I have a favor to ask of you.
I am looking Magician Elder who goes by the name of Hermes Trismegistus.
Last I heard, he was somewhere in the desert. Can you check it out for me?
]])

houseofhermes:getStartNPC():setConversation(houseofhermes:getActiveConvo())
houseofhermes:setActivecyConvo([[
Thank you very much. You should be able to find the Warp upstairs that will take you straight to the desert.
]])

houseofhermes:setActivecnConvo([[
I see that you're busy. Let me know when you can find Hermes for me.
]])

houseofhermes:setStartedConvo([[
I heard Hermes authored the Emerald Tablet. I need to conduct some research.
Have you found him yet?
]])

houseofhermes:setStartedcnConvo([[
I am patient. Let me know when you went to the desert.
I will reward you handsomely, Elliot.
]])

houseofhermes:setStartedcyfConvo([[
Are you sure you went? Just go upstairs to head to the desert.
I really need this book.
]])

houseofhermes:setStartedcytConvo([[
HE WASN'T THERE? Hmm. That's interesting. Maybe Delphine knows where Hermes may have went.
Here is a little something I had laying around.
]])

houseofhermes:setDoneConvo([[
I hear Hermes authored the Emerald Tablet. So many unlocked mysteries...
]])

houseofhermes:pushItemsGive("Carbon")
houseofhermes:pushItemsGive("Carbon")
houseofhermes:pushItemsGive("Oxygen")
qm:addQuest(houseofhermes)