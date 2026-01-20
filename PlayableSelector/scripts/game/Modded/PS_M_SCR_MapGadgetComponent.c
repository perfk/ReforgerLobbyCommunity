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

		container.Get("m_sProtractorTexture", m_sProtractorTexture);
		container.Get("m_fRulerLength", m_fRulerLength);
	}
}