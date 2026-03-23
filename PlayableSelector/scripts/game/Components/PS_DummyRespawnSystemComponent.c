class PS_DummyRespawnSystemComponentClass : SCR_RespawnSystemComponentClass
{
}

//! Scripted implementation that handles spawning and respawning of players.
//! Should be attached to a GameMode entity.
[ComponentEditorProps(icon: HYBRID_COMPONENT_ICON)]
class PS_DummyRespawnSystemComponent : SCR_RespawnSystemComponent
{
	//------------------------------------------------------------------------------------------------
	//! \param[in] requestComponent
	//! \param[in] response
	//! \param[in] data
	//! \return
	override SCR_BaseSpawnPointRequestResultInfo GetSpawnPointRequestResultInfo(SCR_SpawnRequestComponent requestComponent, SCR_ESpawnResult response, SCR_SpawnData data){	return null;	} 
	static override SCR_RespawnSystemComponent GetInstance()	{return null;}
	override RplComponent GetRplComponent()	{return null;}
	static override MenuBase OpenRespawnMenu()	{return null;} 
	static override void CloseRespawnMenu()	{return;} 
	override void ServerSetEnableRespawn(bool enableSpawning){return;}  
	override bool IsRespawnEnabled()	{return false;} 
	override bool IsPauseMenuRespawnEnabled() {return null;} 
	override bool IsFactionChangeAllowed() {return false;} 
	override ScriptInvoker GetOnRespawnEnabledChanged() {return null;} 
	override void OnPlayerRegistered_S(int playerId) {return;}	
	override void OnInit(IEntity owner) {return;}
	override void OnPlayerAuditSuccess_S(int playerId)	{return;}
	override void OnPlayerDisconnected_S(int playerId, KickCauseCode cause, int timeout)	{return;}
	override void OnPlayerDeleted_S(int playerId) {return;}
}