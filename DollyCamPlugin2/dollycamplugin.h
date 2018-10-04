#pragma once
#pragma comment(lib, "BakkesMod.lib")
#include "bakkesmod\plugin\bakkesmodplugin.h"
#include "dollycam.h"

class DollyCamPlugin : public BakkesMod::Plugin::BakkesModPlugin
{
private:
	std::shared_ptr<DollyCam> dollyCam;
	std::shared_ptr<bool> renderCameraPath;
	CameraSnapshot selectedSnapshot;
	bool IsApplicable();
public:
	virtual void onLoad();
	virtual void onUnload();

	//Info/debug methods
	void PrintSnapshotInfo(CameraSnapshot shot);

	//Engine hooks
	void onReplayOpen(std::string funcName);
	void onReplayClose(std::string funcName);
	void onTick(std::string funcName);
	void onRender(CanvasWrapper canvas);

	//Console command handlers
	void OnAllCommand(vector<string> params);
	void OnCamCommand(vector<string> params);
	void OnInReplayCommand(vector<string> params);
	void OnReplayCommand(vector<string> params);
	void OnSnapshotCommand(vector<string> params);
	void OnSnapshotModifyCommand(vector<string> params);

	void OnLiveCommand(vector<string> params);

	//Cvar change listeners
	void OnInterpModeChanged(string oldValue, CVarWrapper newCvar);
	void OnRenderFramesChanged(string oldValue, CVarWrapper newCvar);
	void OnChaikinChanged(string oldValue, CVarWrapper newCvar);

	//Interp config methods
	void OnBezierCommand(vector<string> params);
};
