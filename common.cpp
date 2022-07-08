#include "common.h"
#include "Entity.h"
#include "PlayerInfo.h"
#include "modelindices.h"
#include "Script.h"
#include "ScriptCommands.h"
#include "Pools.h"
#include "World.h"
#include "General.h"


float crossColoring = 136.0f;	// ZAdd: Auto-aim crosshair color value
float tonyHealth;
float LeftOffset = (-0.7f);
float wManAimFireIns = 0;
float wManAimShot = 0;
float controlValue = 1;
float lengthBeforeAiming = 0;
float freeAimIs = 0;
float bTearg = 0;
bool bDontFallOffCheat = false;	// ZAdd: For Never fall off bikes cheat
bool hasPassedMission = false;
float hasFailedMission;
bool bDrunkCheatEnabled = false;
bool bGodMode = false;
bool bAimOfDeath = false;
int bloodAlpha = 180;	// ZAdd: Blood pool transparency
bool bFlappyBirdCheat = false;
bool isTryingtosave = false;
bool isReallyTryingtosave = false;
bool cutSkipper = false;
bool sgBoatHealth = false;
bool bNeverWanted = false;
bool bIgnored = false;

void SpawnBodyCast()
{
	int mi = MI_BODYCAST >= 0 ? MI_BODYCAST : CTheScripts::UsedObjectArray[-MI_BODYCAST].index;
	CObject *pObj = new CObject(mi, false);
	;
	pObj->ObjectCreatedBy = MISSION_OBJECT;
	CVector pos = CVector(-477.71, 544, 152);
	if(pos.z <= MAP_Z_LOW_LIMIT) pos.z = CWorld::FindGroundZForCoord(pos.x, pos.y);
	pObj->SetPosition(pos);
	pObj->SetOrientation(-0.3f, -0.1f, 4.7f);
	pObj->GetMatrix().UpdateRW();
	pObj->UpdateRwFrame();
	CBaseModelInfo *pModelInfo = CModelInfo::GetModelInfo(mi);
	if(pModelInfo->IsBuilding() && ((CSimpleModelInfo *)pModelInfo)->m_isBigBuilding) pObj->SetupBigBuilding();
	CTheScripts::ClearSpaceForMissionEntity(pos, pObj);
	switch(CGeneral::GetRandomNumberInRange(0, 10)) 
	{
	
	case 5:
		CWorld::Add(pObj);
		break;
	
	default: break;
		
	}
	SET_INTEGER_PARAM(0, CPools::GetObjectPool()->GetIndex(pObj));
}

float arrowr = 0;
float arrowg = 0;
float arrowb = 0;
bool screenDrops;

