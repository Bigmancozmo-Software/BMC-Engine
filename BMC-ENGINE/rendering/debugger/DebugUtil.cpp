#include "DebugUtil.h"

DebugUtil::DebugUtil(GLFWwindow* window)
{
	this->window = window;
}

void DebugUtil::draw()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin("Debugging Tools");
	ImGui::SetWindowCollapsed(true, ImGuiCond_Once);
	ImGui::SetWindowPos(ImVec2(10, 10), ImGuiCond_Once);
	ImGui::Text("These are the DEBUGGING TOOLS.\nMake sure you know what you're doing!");
	ImGui::Checkbox("Antialiasing", &(DebugSettings::useAntiAliasing));
	ImGui::SliderFloat("Render Scale", &(DebugSettings::renderScale), 0.0f, 5.0f);
	resetScale = ImGui::Button("Reset Scale", ImVec2(100.0f, 20.0f));
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
