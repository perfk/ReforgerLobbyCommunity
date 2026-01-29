modded class SCR_MapGadgetComponent
{
	void SetRuler(ResourceName mapPrefab)
	{
		Resource resource = BaseContainerTools.LoadContainer(mapPrefab);
		BaseContainer pefabContainer = resource.GetResource().ToBaseContainer();
		
		BaseContainerList components = pefabContainer.GetObjectArray("components");
		
		BaseContainer container;
		for (int c = components.Count() - 1; c >= 0; c--)
		{
			container = components.Get(c);
			typename type = container.GetClassName().ToType();
			
			if (type && type.IsInherited(SCR_MapGadgetComponent))
				break;
			
			container = null;
		}
		
		if(!container)
			return;

		ResourceName protractorTexture;
		float rulerLength;
		container.Get("m_sProtractorTexture", protractorTexture);
		container.Get("m_fRulerLength", rulerLength);
		
		SCR_MapGadgetComponentClass data = SCR_MapGadgetComponentClass.Cast(GetComponentData(GetOwner()));
		if (!data)
			return;
		
		data.SetProtractorTexture(protractorTexture);
		data.SetRulerLength(rulerLength);
	}
}

modded class SCR_MapGadgetComponentClass
{
	void SetProtractorTexture(ResourceName texture)
	{
		m_sProtractorTexture = texture;
	}
	
	void SetRulerLength(float length)
	{
		m_fRulerLength = length;
	}
}