#if defined _smac_included
#endinput
#endif
#define _smac_included

#include <smac_stocks>

/* Globals */
#define SMAC_VERSION	"0.8.7.0"
#define SMAC_URL		"https://bitbucket.org/xCoderx/sourcemod-anti-cheat/"
#define SMAC_AUTHOR		"SMAC Development Team"
#define SMAC_MOD_ERROR	"This module will not work for this mod and should be removed."

enum GameType {
	Game_Unknown = 0,
	Game_CSS,
	Game_TF2,
	Game_DODS,
	Game_INSMOD,
	Game_L4D,
	Game_L4D2,
	Game_HL2DM,
	Game_FOF,
	Game_GMOD,
	Game_HL2CTF,
	Game_HIDDEN,
	Game_ND,
	Game_CSGO,
};

enum DetectionType {
	Detection_Unknown = 0,
	
	// smac_aimbot
	Detection_Aimbot = 100,
	
	// smac_autotrigger
	Detection_AutoTrigger = 200,
	
	// smac_client
	Detection_NameChangeSpam = 300,
	
	// smac_commands
	Detection_CommandSpamming = 400,
	Detection_BannedCommand,
	
	// smac_cvars
	Detection_CvarViolation = 500,
	
	// smac_eyetest
	Detection_UserCmdReuse = 600,
	Detection_UserCmdTamperingTickcount,
	Detection_UserCmdTamperingButtons,
	Detection_Eyeangles,
	
	// smac_speedhack
	Detection_Speedhack = 700,
	
	// smac_spinhack
	Detection_Spinhack = 800,
	
	// smac_eac_banlist
	Detection_GlobalBanned_EAC = 900,
	
	// smac_esea_banlist
	Detection_GlobalBanned_ESEA = 1000,
	
	// smac_hl2dm_fixes
	Detection_GravityGunExploit = 1100,
	
	// smac_kac_banlist
	Detection_GlobalBanned_KAC = 1200,
};

/* Natives */
native GameType:SMAC_GetGameType();
native SMAC_Log(const String:format[], any:...);
native SMAC_LogAction(client, const String:format[], any:...);
native SMAC_Ban(client, const String:reason[], any:...);
native SMAC_PrintAdminNotice(const String:format[], any:...);
native Handle:SMAC_CreateConVar(const String:name[], const String:defaultValue[], const String:description[]="", flags=0, bool:hasMin=false, Float:min=0.0, bool:hasMax=false, Float:max=0.0);
native Action:SMAC_CheatDetected(client, DetectionType:type = Detection_Unknown, Handle:info = INVALID_HANDLE);

/* Forwards */
forward Action:SMAC_OnCheatDetected(client, const String:module[], DetectionType:type, Handle:info);


public SharedPlugin:__pl_smac = 
{
	name = "smac",
	file = "smac.smx",
	#if defined REQUIRE_PLUGIN
	required = 1,
	#else
	required = 0,
	#endif
};

#if !defined REQUIRE_PLUGIN
public __pl_smac_SetNTVOptional()
{
	MarkNativeAsOptional("SMAC_GetGameType");
	MarkNativeAsOptional("SMAC_Log");
	MarkNativeAsOptional("SMAC_LogAction");
	MarkNativeAsOptional("SMAC_Ban");
	MarkNativeAsOptional("SMAC_PrintAdminNotice");
	MarkNativeAsOptional("SMAC_CreateConVar");
	MarkNativeAsOptional("SMAC_CheatDetected");
}
#endif