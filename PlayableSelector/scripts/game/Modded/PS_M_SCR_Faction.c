modded class SCR_Faction
{
	[Attribute(defvalue: "{922F95F91943F69A}Prefabs/Items/Equipment/Maps/Map_Paper_01/PaperMap_01_folded_US.et", desc: "In Reforger Lobby what map prefab is used for this faction")]
	protected ResourceName m_rMapPrefab;
	
	ResourceName GetMapPrefab()
	{
		return m_rMapPrefab;
	}
}