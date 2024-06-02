#include "DebugUtil.h"

DebugUtil::DebugUtil(GLFWwindow* window)
{
	translator = new Translator(main::locale);
	this->window = window;
}

DebugUtil::~DebugUtil()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	delete translator;
}

void DebugUtil::draw()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin(translator->translate("window.title.debugger").c_str());
	ImGui::SetWindowCollapsed(true, ImGuiCond_Once);
	ImGui::SetWindowPos(ImVec2(10, 10), ImGuiCond_Once);
	ImGui::Text((translator->translate("window.description.debugger_line1") + "\n" + translator->translate("window.description.debugger_line2")).c_str());
	ImGui::Checkbox("Antialiasing", &(DebugSettings::useAntiAliasing));
	ImGui::SliderFloat("Render Scale", &(DebugSettings::renderScale), 0.0f, 5.0f);
	resetScale = ImGui::Button("Reset Scale", ImVec2(100.0f, 20.0f));
	ImGui::Text("\nCamera Settings");
	ImGui::SliderFloat("Camera Speed", &(DebugSettings::camSpeed), 0.001f, 0.1f);
	ImGui::SliderFloat("Camera Sensitivity", &(DebugSettings::camSensitivity), 25.0f, 500.0f);
	ImGui::SliderFloat("Camera FOV", &(DebugSettings::camFOV), 30.0f, 180.0f);
	ImGui::End();

	//ImGui::ShowDemoWindow();

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
