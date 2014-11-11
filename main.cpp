#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC

#include "stdafx.h"
#include "Game.h"
#include <iostream>




int main()
{
	Game thisShit;
	thisShit.run();
	
	return 0;
}

/*TO DO

--Set facing direction dependent on velocities than inputs.
--Cast class
--Spell class?

--Make deep copies of items for CraftTable. 
--



-NPC Manager ??? Why???



-Player vs Solid Objs (including boundaries and solid objs)


-Use Items
-----Display an orange box w/ opacity 128 behind the item. (**This item is where your cursor is hovering**)

-----LMouse button down
------------scale that item by 1.25x
------------Change the position of the item to the cursor -x.off and -y.off
-----LMouse button up
------------Check to see if an item exists there
----------------------if so, swap
----------------------if not, place. Turn old to NULL

-Interface (HP Bar, MP Bar, Exp Bar)
--Add Exp Bar
-Quests
--Implement To Kill Quests.
--Implement Go_To_Locataion.

-------------------------------------------------------------------------
- aX + bY + cZ ... = dF
----------ex: H2O   (2 H2 || 4 H) + 2O2 = 2H2O
----------ex: etc....diamond = C ...........graphene = C


*/
/*
-Collision
-------Against level boundaries
-Textbox system**



DAT GUD SHIT
Clannad - Dango Daikazoku (Dango My Nigga Remix ft. Busta Rhymes)
Nightcore Stutter
Biggie JayJay the Train...?
Kyla La Grange - Cut your Teeth Kygo Remix
Vinnie Maniscalco - TaKillya
Requested by Nexuztv
[Electro] - OVERWERK - House (feat. Nick Nikon) [Monstercat Release]




*/