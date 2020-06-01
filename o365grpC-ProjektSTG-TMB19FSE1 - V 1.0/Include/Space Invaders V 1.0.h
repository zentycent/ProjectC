/******************************************************************************/
/*																										*/
/*	Project:			SS 2020 Space Invaders V 1.0.sln										*/
/*	Module Name:	Space Invaders V 1.0.h													*/
/*																										*/
/*	Content:			main(...)																	*/
/*																										*/
/*	Hint:				As a convention, all places marked "####" are to be treated	*/
/*						as UNDER CONSTRUCTION or there are KNOWN ERRORS around!		*/
/*						...																			*/
/*																										*/
/*	Author:			YouB																			*/
/*	Copyright:		© 2020 YouB																	*/
/*																										*/
/*	Revisions:																						*/
/*	1.00				30.01.2020 Initial phase												*/
/*																										*/
/* All Rights Reserved.																			*/
/* No part of this code or any of its contents may be reproduced, copied,		*/
/*	modified or adapted, without the prior written consent of the author,		*/
/*	unless otherwise indicated for stand-alone materials.								*/
/*																										*/
/******************************************************************************/

// Was here before? If not, define the H-flag for further calls and add the
// contents of the file to the actual project! Under WINDOWS, one can use
// #pragma once
   #ifndef _SPACE_INVADERS_V_1_0_DEF_H_													//
   #define _SPACE_INVADERS_V_1_0_DEF_H_													//

//	Nice place for special Space Invaders defines, structs, enums, ...

//	Handlers during gaming
	extern void SpaceInvadersApplicationHandler(void);									//
	extern void SpaceInvadersInputHandler(void);											//
	extern void SpaceInvadersTimerHandler(void);											//

//	Done
	#endif // _SPACE_INVADERS_V_1_0_DEF_H_
