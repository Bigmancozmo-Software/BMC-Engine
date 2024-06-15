#include "DebugUtil.h"

DebugUtil::DebugUtil(GLFWwindow* window)
{
	this->window = window;
}

DebugUtil::~DebugUtil()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void DebugUtil::draw()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin(main::translate("window.debugger.title").c_str());
	ImGui::SetWindowCollapsed(true, ImGuiCond_Once);
	ImGui::SetWindowPos(ImVec2(10, 10), ImGuiCond_Once);
	ImGui::Text((main::translate("window.debugger.description.line1") + "\n" + main::translate("window.debugger.description.line2")).c_str());

	// Rendering Options
	ImGui::Checkbox(main::translate("settings.render.option.antialiasing").c_str(), &(DebugSettings::useAntiAliasing));
	ImGui::SliderFloat(main::translate("settings.render.option.scale").c_str(), &(DebugSettings::renderScale), 0.0f, 5.0f);
	resetScale = ImGui::Button(main::translate("settings.render.button.scale.reset").c_str(), ImVec2(100.0f, 20.0f));

	// Camera Options
	ImGui::Text(("\n" + main::translate("settings.camera.header")).c_str());
	ImGui::SliderFloat(main::translate("settings.camera.option.speed").c_str(), &(DebugSettings::camSpeed), 0.001f, 0.1f);
	ImGui::SliderFloat(main::translate("settings.camera.option.sensitivity").c_str(), &(DebugSettings::camSensitivity), 25.0f, 500.0f);
	ImGui::SliderFloat(main::translate("settings.camera.option.fov").c_str(), &(DebugSettings::camFOV), 30.0f, 180.0f);

	ImGui::End();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	processVars();
}

void DebugUtil::processVars()
{
	// Some settings, such as Render Scale, must be processed in main.cpp
	if (DebugSettings::useAntiAliasing) { glEnable(GL_MULTISAMPLE); } else { glDisable(GL_MULTISAMPLE); }
	if (resetScale) { DebugSettings::renderScale = 1.0f; }
}
