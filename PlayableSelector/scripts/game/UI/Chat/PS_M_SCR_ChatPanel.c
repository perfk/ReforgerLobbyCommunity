modded class SCR_ChatPanel : ScriptedWidgetComponent
{
	protected const int CHAT_ACTIVE_MS = 120000;

	protected int m_iLastSentTick = 0;

	override protected void UpdateChatMessages()
	{
		if (ShouldShowChat())
			super.UpdateChatMessages();
		else
			HideAllMessageLines();
	}

	override protected void SendMessage()
	{
		super.SendMessage();
		m_iLastSentTick = System.GetTickCount();
	}

	protected bool ShouldShowChat()
	{
		PS_PlayableManager playableManager = PS_PlayableManager.GetInstance();
		if (!playableManager)
			return true;

		PlayerController playerController = GetGame().GetPlayerController();
		if (!playerController)
			return true;

		PS_GameModeCoop gameMode = PS_GameModeCoop.Cast(GetGame().GetGameMode());
		if (!gameMode)
			return true;

		if (!gameMode.IsChatDisabled())
			return true;

		if (gameMode.GetState() != SCR_EGameModeState.GAME)
			return true;

		int playerId = playerController.GetPlayerId();

		FactionKey factionKey = playableManager.GetPlayerFactionKey(playerId);
		if (factionKey == "")
			return true;

		if (PS_PlayersHelper.IsAdminOrServer())
			return true;

		if (System.GetTickCount() - m_iLastSentTick < CHAT_ACTIVE_MS)
			return true;

		return false;
	}

	protected void HideAllMessageLines()
	{
		foreach (SCR_ChatMessageLineComponent lineComp : m_aMessageLines)
		{
			if (!lineComp)
				continue;

			lineComp.SetVisible(false);
		}
	}

	SCR_ChatPanelWidgets PS_GetWidgets()
	{
		return m_Widgets;
	}
}
